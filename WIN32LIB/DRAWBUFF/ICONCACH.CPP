/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#define	WIN32_LEAN_AND_MEAN
#define	_WIN32

#include <windows.h>
#include "ddraw.h"
#include "misc.h"
#include "iconcach.h"
#include "gbuffer.h"


static	DDSURFACEDESC	VideoSurfaceDescription;

IconCacheClass	CachedIcons[MAX_CACHED_ICONS];

extern "C"{
IconSetType		IconSetList[MAX_ICON_SETS];
short				IconCacheLookup[MAX_LOOKUP_ENTRIES];
}

int		CachedIconsDrawn=0;		//Counter of number of cache hits
int		UnCachedIconsDrawn=0;	//Counter of number of cache misses
BOOL	CacheMemoryExhausted;	//Flag set if we have run out of video RAM




/***********************************************************************************************
 * Optimise_Video_Memory_Cache -- optimises usage of video memory                              *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   TRUE if memory was freed up                                                       *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/29/95 12:47PM ST : Created                                                            *
 *=============================================================================================*/
BOOL Optimize_Video_Memory_Cache (void)
{

	if (CacheMemoryExhausted &&
		(UnCachedIconsDrawn+CachedIconsDrawn > 1000) &&
		UnCachedIconsDrawn > CachedIconsDrawn){

		int	cache_misses[MAX_CACHED_ICONS];
		int	cache_hits[MAX_CACHED_ICONS];
		int	total_cache_misses=0;
		int	total_cache_hits=0;
		int	counter;
		int	i;
		int	j;
		int	temp;
		BOOL	swapped;

		/*
		** make list of icons that have failed to cache more than 5 times
		*/
		for (counter=0 ; counter<MAX_CACHED_ICONS ; counter++){

			if (CachedIcons[counter].TimesFailed>5){
				cache_misses[total_cache_misses++] = counter;
			}
		}

		/*
		** Make list of icons that have been drawn less than 3 times
		*/
		for (counter=0 ; counter<MAX_CACHED_ICONS ; counter++){

			if (CachedIcons[counter].TimesDrawn<3){
				cache_hits[total_cache_hits++] = counter;
			}
		}


		/*
		** Sort drawn icons into order
		*/
		if (total_cache_hits > 1){
			for (i = 0 ; i<total_cache_hits ; i++){
				swapped=FALSE;
				for (j=0 ; j<total_cache_hits-1 ; j++){

					if (CachedIcons[cache_hits[j]].TimesDrawn > CachedIcons[cache_hits[j+1]].TimesDrawn){
						temp=cache_hits[j];
						cache_hits[j]=cache_hits[j+1];
						cache_hits[j+1]=temp;
						swapped = TRUE;
					}
				}
				if (!swapped) break;
			}
		}


		/*
		** Uncache icons up to the number of failed icons
		*/

		for (counter=0 ; counter<total_cache_misses && counter<total_cache_hits; counter++){
			CachedIcons[cache_hits[counter]].Uncache_It();
		}

		CacheMemoryExhausted=FALSE;
		CachedIconsDrawn=0;
		UnCachedIconsDrawn=0;
		return (TRUE);
	}
	return (FALSE);

}





/***********************************************************************************************
 * Cache_New_Icon -- cache a registered icon to video memory                                   *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    icon_index -- index into registered icon table of icon to cache                   *
 *           icon_ptr -- ptr to icon data                                                      *
 *                                                                                             *
 * OUTPUT:   BOOL success                                                                      *
 *                                                                                             *
 * WARNINGS: icon must already have been registered and assigned an index                      *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:36AM ST : Created                                                             *
 *=============================================================================================*/
BOOL Cache_New_Icon (int icon_index, void *icon_ptr)
{
	if (!CacheMemoryExhausted){
		return (CachedIcons[icon_index].Cache_It(icon_ptr));
	} else {
		CachedIcons[icon_index].TimesFailed++;
		if (Optimize_Video_Memory_Cache()){
			return (CachedIcons[icon_index].Cache_It(icon_ptr));
		} else {
			return (FALSE);
		}
	}
}





/***********************************************************************************************
 * Invalidat_Cached_Icons -- used to release any icons that have been cached                   *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:37AM ST : Created                                                             *
 *=============================================================================================*/
void Invalidate_Cached_Icons (void)
{
	int i;

	for (i=0 ; i<MAX_CACHED_ICONS ; i++){
		CachedIcons[i].Uncache_It();
	}

	memset (&IconCacheLookup[0] , -1 ,MAX_LOOKUP_ENTRIES*sizeof(IconCacheLookup[0]));

	for (i=0 ; i<MAX_ICON_SETS ; i++){
		IconSetList[i].IconSetPtr=NULL;
	}

	CacheMemoryExhausted=FALSE;
}




/***********************************************************************************************
 * Restore_Cached_Icons -- re-cache icons into video memory after a loss of focus              *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: Assumes that the pointers that were originally used to cache the icons            *
 *           are still valid.                                                                  *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:38AM ST : Created                                                             *
 *=============================================================================================*/
void Restore_Cached_Icons (void)
{
	for (int i=0 ; i<MAX_CACHED_ICONS ; i++){
		CachedIcons[i].Restore();
	}
	CacheMemoryExhausted=FALSE;
}



/***********************************************************************************************
 * Register_Icon_Set -- used to register an icon set as cachable                               *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    icon_data - ptr to icon set                                                       *
 *           pre_cache -- should we pre-cache the icon data?                                   *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:39AM ST : Created                                                             *
 *=============================================================================================*/
void Register_Icon_Set (void *icon_data , BOOL pre_cache)
{

	for (int i=0 ; i<MAX_ICON_SETS ; i++){
		if (!IconSetList[i].IconSetPtr){
			IconSetList[i].IconSetPtr = (IControl_Type*)icon_data;

			if (i){
				IControl_Type *previous_set = IconSetList[i-1].IconSetPtr;
				IconSetList[i].IconListOffset = IconSetList[i-1].IconListOffset + ((int)previous_set->Count)*2;
				if (IconSetList[i].IconListOffset > MAX_LOOKUP_ENTRIES*2){
					IconSetList[i].IconSetPtr = NULL;
				}
			} else {
				IconSetList[i].IconListOffset = 0;
			}

			if (pre_cache){
				for (i=0 ; i<256 ; i++){
					Is_Icon_Cached(icon_data,i);
				}
			}
			return;
		}
	}
}



/***********************************************************************************************
 * Get_Free_Cache_Slot -- find a free slot in which to cache an icon                           *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   int - icon index                                                                  *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:40AM ST : Created                                                             *
 *=============================================================================================*/
int Get_Free_Cache_Slot (void)
{
	for (int i=0 ; i<MAX_CACHED_ICONS ; i++){
		if (!CachedIcons[i].Get_Is_Cached()){
			return (i);
		}
	}
	return (-1);
}



/***********************************************************************************************
 * ICC::IconCacheClass -- constructor for icon cache class                                     *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:41AM ST : Created                                                             *
 *=============================================================================================*/
IconCacheClass::IconCacheClass (void)
{
	IsCached			=FALSE;
	SurfaceLost		=FALSE;
	DrawFrequency	=0;
	CacheSurface	=NULL;
	IconSource		=NULL;
}



/***********************************************************************************************
 * ICC::~IconCacheClass -- destructor for icon cache class                                     *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:41AM ST : Created                                                             *
 *=============================================================================================*/
IconCacheClass::~IconCacheClass (void)
{
	if (IsCached && CacheSurface){
		CacheSurface->Release();
	}
}




/***********************************************************************************************
 * ICC::Restore -- Restores the icons video surface memory and reloads it based on the original*
 *                 icon pointer                                                                *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: Relies on the icons original pointer still being valie                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:43AM ST : Created                                                             *
 *=============================================================================================*/
void IconCacheClass::Restore (void)
{
	if (IsCached && CacheSurface){
		CacheSurface->Restore();
		if (IconSource){
			Cache_It(IconSource);
		}
	}
}


/***********************************************************************************************
 * ICC::Cache_It -- allocate video memory and copy an icon to it                               *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    icon_ptr -- ptr to icon data                                                      *
 *                                                                                             *
 * OUTPUT:   bool -- success?                                                                  *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:44AM ST : Created                                                             *
 *=============================================================================================*/
BOOL IconCacheClass::Cache_It (void *icon_ptr)
{
	DDSCAPS	surface_capabilities;
	BOOL		return_value;

	/*
	** If we dont have a direct draw interface yet then just fail
	*/
	if (!DirectDrawObject) return(FALSE);

	/*
	** Set up the description of the surface we want to create
	*/
	memset (&VideoSurfaceDescription , 0 , sizeof ( VideoSurfaceDescription ));

	VideoSurfaceDescription.dwSize			= sizeof( VideoSurfaceDescription );
	VideoSurfaceDescription.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
	VideoSurfaceDescription.dwFlags			= DDSD_CAPS |	DDSD_HEIGHT | DDSD_WIDTH;
	VideoSurfaceDescription.dwHeight			= ICON_WIDTH;
	VideoSurfaceDescription.dwWidth			= ICON_HEIGHT;

	/*
	** If this cache object doesnt already have a surface then create one
	*/
	if (!CacheSurface){
		if (DD_OK!=DirectDrawObject->CreateSurface( &VideoSurfaceDescription , &CacheSurface , NULL)){
			CacheMemoryExhausted = TRUE;
			return(FALSE);
		}

	}

	/*
	** Make sure the surface we created isnt really in system memory
	*/
	if (DD_OK != CacheSurface->GetCaps(&surface_capabilities)){
		return(FALSE);
	}

	if ((DDSCAPS_SYSTEMMEMORY & surface_capabilities.dwCaps) == DDSCAPS_SYSTEMMEMORY){
		CacheSurface->Release();
		return(FALSE);
	}

	return_value=FALSE;
	/*
	** Lock the surface so we can copy the icon to it
	*/
	if (DD_OK== CacheSurface->Lock ( NULL
								, &(VideoSurfaceDescription)
								, DDLOCK_WAIT
								, NULL)){
		/*
		** Copy the icon to the surface and flag that icon is cached
		*/
		Cache_Copy_Icon (icon_ptr , VideoSurfaceDescription.lpSurface , VideoSurfaceDescription.lPitch);
		IsCached=TRUE;
		SurfaceLost=FALSE;
		IconSource=icon_ptr;
		return_value=TRUE;
	}
	CacheSurface->Unlock(NULL);
	return (return_value);
}


/***********************************************************************************************
 * ICC::Uncache_It -- release the video memory used to cache an icon                           *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:48AM ST : Created                                                             *
 *=============================================================================================*/
void IconCacheClass::Uncache_It(void)
{

	if (IsCached && CacheSurface){
		CacheSurface->Release();
		IsCached=FALSE;
		CacheSurface=NULL;
		IconSource=NULL;
		CacheMemoryExhausted=FALSE;
	}
}



/***********************************************************************************************
 * ICC::Draw_It -- use the blitter to draw a cached icon                                       *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    surface to draw to                                                                *
 *           x coord to draw to (relative to window)                                           *
 *           y coord to draw to (relative to window)                                           *
 *           window left coord                                                                 *
 *           window top coord                                                                  *
 *           window width                                                                      *
 *           window height                                                                     *
 *                                                                                             *
 * OUTPUT:   Nothing                                                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/13/95 9:48AM ST : Created                                                             *
 *=============================================================================================*/
void IconCacheClass::Draw_It (LPDIRECTDRAWSURFACE dest_surface , int x_pixel, int y_pixel, int window_left , int window_top , int window_width , int window_height)
{
	RECT		source_rectangle;
	RECT		dest_rectangle;
	int		clip;
	HRESULT	return_code;

	/*
	** Set up the source and destination coordinates as required by direct draw
	*/
	source_rectangle.left 	= 0;
	source_rectangle.top  	= 0;
	source_rectangle.right	= ICON_WIDTH;
	source_rectangle.bottom	= ICON_HEIGHT;

	dest_rectangle.left 	= window_left+x_pixel;
	dest_rectangle.top  	= window_top+y_pixel;
	dest_rectangle.right	= dest_rectangle.left+ICON_WIDTH;
	dest_rectangle.bottom	= dest_rectangle.top+ICON_HEIGHT;

	/*
	** Clip the coordinates to the window
	*/
	if (dest_rectangle.left<window_left){
		source_rectangle.left += window_left-dest_rectangle.left;
		dest_rectangle.left=window_left;
	}

	if (dest_rectangle.right>=window_left+window_width){
		clip = dest_rectangle.right-(window_left+window_width);
		source_rectangle.right -= clip;
		dest_rectangle.right -= clip;
	}

	if (dest_rectangle.top<window_top){
		source_rectangle.top += window_top-dest_rectangle.top;
		dest_rectangle.top=window_top;
	}

	if (dest_rectangle.bottom>=window_top+window_height){
		clip = dest_rectangle.bottom-(window_top+window_height);
		source_rectangle.bottom -= clip;
		dest_rectangle.bottom -= clip;
	}

	if (source_rectangle.left>=source_rectangle.right){
		return;
	}

	if (source_rectangle.top>=source_rectangle.bottom){
		return;
	}

	/*
	** Do the blit
	*/
		return_code = dest_surface->Blt (&dest_rectangle ,
													CacheSurface ,
													&source_rectangle ,
													DDBLT_WAIT |
													DDBLT_ASYNC ,
													NULL);

	if (return_code == DDERR_SURFACELOST && Gbuffer_Focus_Loss_Function){
		Gbuffer_Focus_Loss_Function();
	}

	if ( return_code != DDERR_SURFACELOST && return_code != DD_OK ) {
		char temp[100];
		sprintf(temp,"DD Error code %d\n", return_code & 0xFFFF);
		OutputDebugString(temp);
	}

	TimesDrawn++;

}
