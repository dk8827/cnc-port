/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "gbuffer.h"

/***************************************************************************
 * Draw_Rect -- Draws a rectangle to the LogicPage.                        *
 *                                                                         *
 *    This routine will draw a rectangle to the LogicPage.  The rectangle  *
 *    doesn't have to be aligned on the vertical or horizontal axis.  In   *
 *    fact, it doesn't even have to be a rectangle.  The "square" can be   *
 *    skewed.                                                              *
 *                                                                         *
 * INPUT:   x1_pixel, y1_pixel   -- One corner.                            *
 *                                                                         *
 *          x2_pixel, y2_pixel   -- The other corner.                      *
 *                                                                         *
 *          color                -- The color to draw the lines.           *
 *                                                                         *
 * OUTPUT:  none                                                           *
 *                                                                         *
 * WARNINGS:   None, but the rectangle will be clipped to the current      *
 *             draw line clipping rectangle.                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   08/20/1993 JLB : Created.                                             *
 *=========================================================================*/
VOID GraphicViewPortClass::Draw_Rect(int x1_pixel, int y1_pixel, int x2_pixel, int y2_pixel, unsigned char color)
{
	Lock();
	Draw_Line(x1_pixel, y1_pixel, x2_pixel, y1_pixel, color);
	Draw_Line(x1_pixel, y2_pixel, x2_pixel, y2_pixel, color);
	Draw_Line(x1_pixel, y1_pixel, x1_pixel, y2_pixel, color);
	Draw_Line(x2_pixel, y1_pixel, x2_pixel, y2_pixel, color);
	Unlock();
}
