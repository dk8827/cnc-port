/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Wed Jul 29 16:25:34 1998
 */
/* Compiler settings for WOLAPI.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __WOLAPI_h__
#define __WOLAPI_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IRTPatcher_FWD_DEFINED__
#define __IRTPatcher_FWD_DEFINED__
typedef interface IRTPatcher IRTPatcher;
#endif 	/* __IRTPatcher_FWD_DEFINED__ */


#ifndef __IRTPatcherEvent_FWD_DEFINED__
#define __IRTPatcherEvent_FWD_DEFINED__
typedef interface IRTPatcherEvent IRTPatcherEvent;
#endif 	/* __IRTPatcherEvent_FWD_DEFINED__ */


#ifndef __IChat_FWD_DEFINED__
#define __IChat_FWD_DEFINED__
typedef interface IChat IChat;
#endif 	/* __IChat_FWD_DEFINED__ */


#ifndef __IChatEvent_FWD_DEFINED__
#define __IChatEvent_FWD_DEFINED__
typedef interface IChatEvent IChatEvent;
#endif 	/* __IChatEvent_FWD_DEFINED__ */


#ifndef __IDownload_FWD_DEFINED__
#define __IDownload_FWD_DEFINED__
typedef interface IDownload IDownload;
#endif 	/* __IDownload_FWD_DEFINED__ */


#ifndef __IDownloadEvent_FWD_DEFINED__
#define __IDownloadEvent_FWD_DEFINED__
typedef interface IDownloadEvent IDownloadEvent;
#endif 	/* __IDownloadEvent_FWD_DEFINED__ */


#ifndef __INetUtil_FWD_DEFINED__
#define __INetUtil_FWD_DEFINED__
typedef interface INetUtil INetUtil;
#endif 	/* __INetUtil_FWD_DEFINED__ */


#ifndef __INetUtilEvent_FWD_DEFINED__
#define __INetUtilEvent_FWD_DEFINED__
typedef interface INetUtilEvent INetUtilEvent;
#endif 	/* __INetUtilEvent_FWD_DEFINED__ */


#ifndef __IChat2_FWD_DEFINED__
#define __IChat2_FWD_DEFINED__
typedef interface IChat2 IChat2;
#endif 	/* __IChat2_FWD_DEFINED__ */


#ifndef __IChat2Event_FWD_DEFINED__
#define __IChat2Event_FWD_DEFINED__
typedef interface IChat2Event IChat2Event;
#endif 	/* __IChat2Event_FWD_DEFINED__ */


#ifndef __RTPatcher_FWD_DEFINED__
#define __RTPatcher_FWD_DEFINED__

#ifdef __cplusplus
typedef class RTPatcher RTPatcher;
#else
typedef struct RTPatcher RTPatcher;
#endif /* __cplusplus */

#endif 	/* __RTPatcher_FWD_DEFINED__ */


#ifndef __Chat_FWD_DEFINED__
#define __Chat_FWD_DEFINED__

#ifdef __cplusplus
typedef class Chat Chat;
#else
typedef struct Chat Chat;
#endif /* __cplusplus */

#endif 	/* __Chat_FWD_DEFINED__ */


#ifndef __Download_FWD_DEFINED__
#define __Download_FWD_DEFINED__

#ifdef __cplusplus
typedef class Download Download;
#else
typedef struct Download Download;
#endif /* __cplusplus */

#endif 	/* __Download_FWD_DEFINED__ */


#ifndef __NetUtil_FWD_DEFINED__
#define __NetUtil_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetUtil NetUtil;
#else
typedef struct NetUtil NetUtil;
#endif /* __cplusplus */

#endif 	/* __NetUtil_FWD_DEFINED__ */


#ifndef __Chat2_FWD_DEFINED__
#define __Chat2_FWD_DEFINED__

#ifdef __cplusplus
typedef class Chat2 Chat2;
#else
typedef struct Chat2 Chat2;
#endif /* __cplusplus */

#endif 	/* __Chat2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
//#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IRTPatcher_INTERFACE_DEFINED__
#define __IRTPatcher_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRTPatcher
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 



EXTERN_C const IID IID_IRTPatcher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("925CDEDE-71B9-11D1-B1C5-006097176556")
    IRTPatcher : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ApplyPatch( 
            /* [string][in] */ LPCSTR destpath,
            /* [string][in] */ LPCSTR filename) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PumpMessages( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTPatcherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRTPatcher __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRTPatcher __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRTPatcher __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ApplyPatch )( 
            IRTPatcher __RPC_FAR * This,
            /* [string][in] */ LPCSTR destpath,
            /* [string][in] */ LPCSTR filename);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PumpMessages )( 
            IRTPatcher __RPC_FAR * This);
        
        END_INTERFACE
    } IRTPatcherVtbl;

    interface IRTPatcher
    {
        CONST_VTBL struct IRTPatcherVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTPatcher_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTPatcher_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTPatcher_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTPatcher_ApplyPatch(This,destpath,filename)	\
    (This)->lpVtbl -> ApplyPatch(This,destpath,filename)

#define IRTPatcher_PumpMessages(This)	\
    (This)->lpVtbl -> PumpMessages(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTPatcher_ApplyPatch_Proxy( 
    IRTPatcher __RPC_FAR * This,
    /* [string][in] */ LPCSTR destpath,
    /* [string][in] */ LPCSTR filename);


void __RPC_STUB IRTPatcher_ApplyPatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTPatcher_PumpMessages_Proxy( 
    IRTPatcher __RPC_FAR * This);


void __RPC_STUB IRTPatcher_PumpMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTPatcher_INTERFACE_DEFINED__ */


#ifndef __IRTPatcherEvent_INTERFACE_DEFINED__
#define __IRTPatcherEvent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRTPatcherEvent
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 



EXTERN_C const IID IID_IRTPatcherEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("925CDEE3-71B9-11D1-B1C5-006097176556")
    IRTPatcherEvent : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnProgress( 
            /* [in] */ LPCSTR filename,
            /* [in] */ int progress) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnTermination( 
            /* [in] */ BOOL success) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRTPatcherEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRTPatcherEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRTPatcherEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRTPatcherEvent __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnProgress )( 
            IRTPatcherEvent __RPC_FAR * This,
            /* [in] */ LPCSTR filename,
            /* [in] */ int progress);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTermination )( 
            IRTPatcherEvent __RPC_FAR * This,
            /* [in] */ BOOL success);
        
        END_INTERFACE
    } IRTPatcherEventVtbl;

    interface IRTPatcherEvent
    {
        CONST_VTBL struct IRTPatcherEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRTPatcherEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRTPatcherEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRTPatcherEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRTPatcherEvent_OnProgress(This,filename,progress)	\
    (This)->lpVtbl -> OnProgress(This,filename,progress)

#define IRTPatcherEvent_OnTermination(This,success)	\
    (This)->lpVtbl -> OnTermination(This,success)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTPatcherEvent_OnProgress_Proxy( 
    IRTPatcherEvent __RPC_FAR * This,
    /* [in] */ LPCSTR filename,
    /* [in] */ int progress);


void __RPC_STUB IRTPatcherEvent_OnProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IRTPatcherEvent_OnTermination_Proxy( 
    IRTPatcherEvent __RPC_FAR * This,
    /* [in] */ BOOL success);


void __RPC_STUB IRTPatcherEvent_OnTermination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRTPatcherEvent_INTERFACE_DEFINED__ */


#ifndef __IChat_INTERFACE_DEFINED__
#define __IChat_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IChat
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 


//typedef long time_t;
#include <sys\types.h>

struct  Ladder
    {
    unsigned int sku;
    unsigned int team_no;
    unsigned int wins;
    unsigned int losses;
    unsigned int points;
    unsigned int kills;
    unsigned int rank;
    unsigned int rung;
    unsigned int disconnects;
    unsigned int team_rung;
    unsigned int provisional;
    unsigned int last_game_date;
    unsigned int win_streak;
    unsigned int reserved1;
    unsigned int reserved2;
    struct Ladder __RPC_FAR *next;
    unsigned char login_name[ 40 ];
    };
typedef int GroupID;

struct  Server
    {
    int gametype;
    int chattype;
    int timezone;
    float longitude;
    float lattitude;
    struct Server __RPC_FAR *next;
    unsigned char name[ 71 ];
    unsigned char connlabel[ 5 ];
    unsigned char conndata[ 128 ];
    unsigned char login[ 10 ];
    unsigned char password[ 10 ];
    };
struct  Channel
    {
    int type;
    unsigned int minUsers;
    unsigned int maxUsers;
    unsigned int currentUsers;
    unsigned int official;
    unsigned int tournament;
    unsigned int ingame;
    unsigned int flags;
    unsigned long reserved;
    unsigned long ipaddr;
    int latency;
    int hidden;
    struct Channel __RPC_FAR *next;
    unsigned char name[ 17 ];
    unsigned char topic[ 81 ];
    unsigned char location[ 65 ];
    unsigned char key[ 9 ];
    unsigned char exInfo[ 41 ];
    };
struct  User
    {
    unsigned int flags;
    GroupID group;
    unsigned long reserved;
    unsigned long reserved2;
    unsigned long reserved3;
    unsigned long reserved4;
    unsigned long ipaddr;
    unsigned long squad_icon;
    struct User __RPC_FAR *next;
    unsigned char name[ 10 ];
    unsigned char squadname[ 41 ];
    };
struct  Group
    {
    GroupID ident;
    int type;
    unsigned int members;
    struct Group __RPC_FAR *next;
    unsigned char name[ 65 ];
    };
struct  Update
    {
    unsigned long SKU;
    unsigned long version;
    int required;
    struct Update __RPC_FAR *next;
    unsigned char server[ 65 ];
    unsigned char patchpath[ 256 ];
    unsigned char patchfile[ 33 ];
    unsigned char login[ 33 ];
    unsigned char password[ 65 ];
    unsigned char localpath[ 256 ];
    };
typedef struct Server Server;

typedef struct Channel Channel;

typedef struct User User;

typedef struct Group Group;

typedef struct Update Update;

typedef struct Ladder Ladder;


EXTERN_C const IID IID_IChat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("4DD3BAF4-7579-11D1-B1C6-006097176556")
    IChat : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PumpMessages( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestServerList( 
            /* [in] */ unsigned long SKU,
            /* [in] */ unsigned long current_version,
            /* [in] */ LPCSTR loginname,
            /* [in] */ LPCSTR password,
            /* [in] */ int timeout) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestConnection( 
            /* [in] */ Server __RPC_FAR *server,
            /* [in] */ int timeout,
            int domangle) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelList( 
            /* [in] */ int channelType,
            /* [in] */ int autoping) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelCreate( 
            /* [in] */ Channel __RPC_FAR *channel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelJoin( 
            /* [in] */ Channel __RPC_FAR *channel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelLeave( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestUserList( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestPublicMessage( 
            /* [in] */ LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestPrivateMessage( 
            /* [in] */ User __RPC_FAR *users,
            /* [in] */ LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestLogout( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestPrivateGameOptions( 
            /* [in] */ User __RPC_FAR *users,
            /* [in] */ LPCSTR options) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestPublicGameOptions( 
            /* [in] */ LPCSTR options) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestPublicAction( 
            /* [in] */ LPCSTR action) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestPrivateAction( 
            /* [in] */ User __RPC_FAR *users,
            /* [in] */ LPCSTR action) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestGameStart( 
            /* [in] */ User __RPC_FAR *users) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelTopic( 
            /* [in] */ LPCSTR topic) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [in] */ unsigned long __RPC_FAR *version) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestUserKick( 
            /* [in] */ User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestUserIP( 
            /* [in] */ User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGametypeInfo( 
            unsigned int gtype,
            int icon_size,
            unsigned char __RPC_FAR *__RPC_FAR *bitmap,
            int __RPC_FAR *bmp_bytes,
            LPCSTR __RPC_FAR *name,
            LPCSTR __RPC_FAR *URL) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestFind( 
            User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestPage( 
            User __RPC_FAR *user,
            LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetFindPage( 
            int findOn,
            int pageOn) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSquelch( 
            User __RPC_FAR *user,
            int squelch) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSquelch( 
            User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetChannelFilter( 
            int channelType) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestGameEnd( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetLangFilter( 
            int onoff) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelBan( 
            LPCSTR name,
            int ban) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGametypeList( 
            LPCSTR __RPC_FAR *list) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHelpURL( 
            LPCSTR __RPC_FAR *url) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetProductSKU( 
            unsigned long SKU) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNick( 
            int num,
            LPCSTR __RPC_FAR *nick,
            LPCSTR __RPC_FAR *pass) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetNick( 
            int num,
            LPCSTR nick,
            LPCSTR pass,
            int domangle) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLobbyCount( 
            int __RPC_FAR *count) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestRawMessage( 
            LPCSTR ircmsg) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAttributeValue( 
            LPCSTR attrib,
            LPCSTR __RPC_FAR *value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAttributeValue( 
            LPCSTR attrib,
            LPCSTR value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetChannelExInfo( 
            LPCSTR info) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopAutoping( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChat __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChat __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChat __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PumpMessages )( 
            IChat __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestServerList )( 
            IChat __RPC_FAR * This,
            /* [in] */ unsigned long SKU,
            /* [in] */ unsigned long current_version,
            /* [in] */ LPCSTR loginname,
            /* [in] */ LPCSTR password,
            /* [in] */ int timeout);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestConnection )( 
            IChat __RPC_FAR * This,
            /* [in] */ Server __RPC_FAR *server,
            /* [in] */ int timeout,
            int domangle);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelList )( 
            IChat __RPC_FAR * This,
            /* [in] */ int channelType,
            /* [in] */ int autoping);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelCreate )( 
            IChat __RPC_FAR * This,
            /* [in] */ Channel __RPC_FAR *channel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelJoin )( 
            IChat __RPC_FAR * This,
            /* [in] */ Channel __RPC_FAR *channel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelLeave )( 
            IChat __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestUserList )( 
            IChat __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestPublicMessage )( 
            IChat __RPC_FAR * This,
            /* [in] */ LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestPrivateMessage )( 
            IChat __RPC_FAR * This,
            /* [in] */ User __RPC_FAR *users,
            /* [in] */ LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestLogout )( 
            IChat __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestPrivateGameOptions )( 
            IChat __RPC_FAR * This,
            /* [in] */ User __RPC_FAR *users,
            /* [in] */ LPCSTR options);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestPublicGameOptions )( 
            IChat __RPC_FAR * This,
            /* [in] */ LPCSTR options);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestPublicAction )( 
            IChat __RPC_FAR * This,
            /* [in] */ LPCSTR action);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestPrivateAction )( 
            IChat __RPC_FAR * This,
            /* [in] */ User __RPC_FAR *users,
            /* [in] */ LPCSTR action);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestGameStart )( 
            IChat __RPC_FAR * This,
            /* [in] */ User __RPC_FAR *users);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelTopic )( 
            IChat __RPC_FAR * This,
            /* [in] */ LPCSTR topic);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersion )( 
            IChat __RPC_FAR * This,
            /* [in] */ unsigned long __RPC_FAR *version);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestUserKick )( 
            IChat __RPC_FAR * This,
            /* [in] */ User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestUserIP )( 
            IChat __RPC_FAR * This,
            /* [in] */ User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGametypeInfo )( 
            IChat __RPC_FAR * This,
            unsigned int gtype,
            int icon_size,
            unsigned char __RPC_FAR *__RPC_FAR *bitmap,
            int __RPC_FAR *bmp_bytes,
            LPCSTR __RPC_FAR *name,
            LPCSTR __RPC_FAR *URL);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestFind )( 
            IChat __RPC_FAR * This,
            User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestPage )( 
            IChat __RPC_FAR * This,
            User __RPC_FAR *user,
            LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFindPage )( 
            IChat __RPC_FAR * This,
            int findOn,
            int pageOn);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSquelch )( 
            IChat __RPC_FAR * This,
            User __RPC_FAR *user,
            int squelch);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSquelch )( 
            IChat __RPC_FAR * This,
            User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetChannelFilter )( 
            IChat __RPC_FAR * This,
            int channelType);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestGameEnd )( 
            IChat __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLangFilter )( 
            IChat __RPC_FAR * This,
            int onoff);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelBan )( 
            IChat __RPC_FAR * This,
            LPCSTR name,
            int ban);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGametypeList )( 
            IChat __RPC_FAR * This,
            LPCSTR __RPC_FAR *list);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHelpURL )( 
            IChat __RPC_FAR * This,
            LPCSTR __RPC_FAR *url);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProductSKU )( 
            IChat __RPC_FAR * This,
            unsigned long SKU);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNick )( 
            IChat __RPC_FAR * This,
            int num,
            LPCSTR __RPC_FAR *nick,
            LPCSTR __RPC_FAR *pass);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNick )( 
            IChat __RPC_FAR * This,
            int num,
            LPCSTR nick,
            LPCSTR pass,
            int domangle);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLobbyCount )( 
            IChat __RPC_FAR * This,
            int __RPC_FAR *count);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestRawMessage )( 
            IChat __RPC_FAR * This,
            LPCSTR ircmsg);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttributeValue )( 
            IChat __RPC_FAR * This,
            LPCSTR attrib,
            LPCSTR __RPC_FAR *value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttributeValue )( 
            IChat __RPC_FAR * This,
            LPCSTR attrib,
            LPCSTR value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetChannelExInfo )( 
            IChat __RPC_FAR * This,
            LPCSTR info);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopAutoping )( 
            IChat __RPC_FAR * This);
        
        END_INTERFACE
    } IChatVtbl;

    interface IChat
    {
        CONST_VTBL struct IChatVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChat_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChat_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChat_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChat_PumpMessages(This)	\
    (This)->lpVtbl -> PumpMessages(This)

#define IChat_RequestServerList(This,SKU,current_version,loginname,password,timeout)	\
    (This)->lpVtbl -> RequestServerList(This,SKU,current_version,loginname,password,timeout)

#define IChat_RequestConnection(This,server,timeout,domangle)	\
    (This)->lpVtbl -> RequestConnection(This,server,timeout,domangle)

#define IChat_RequestChannelList(This,channelType,autoping)	\
    (This)->lpVtbl -> RequestChannelList(This,channelType,autoping)

#define IChat_RequestChannelCreate(This,channel)	\
    (This)->lpVtbl -> RequestChannelCreate(This,channel)

#define IChat_RequestChannelJoin(This,channel)	\
    (This)->lpVtbl -> RequestChannelJoin(This,channel)

#define IChat_RequestChannelLeave(This)	\
    (This)->lpVtbl -> RequestChannelLeave(This)

#define IChat_RequestUserList(This)	\
    (This)->lpVtbl -> RequestUserList(This)

#define IChat_RequestPublicMessage(This,message)	\
    (This)->lpVtbl -> RequestPublicMessage(This,message)

#define IChat_RequestPrivateMessage(This,users,message)	\
    (This)->lpVtbl -> RequestPrivateMessage(This,users,message)

#define IChat_RequestLogout(This)	\
    (This)->lpVtbl -> RequestLogout(This)

#define IChat_RequestPrivateGameOptions(This,users,options)	\
    (This)->lpVtbl -> RequestPrivateGameOptions(This,users,options)

#define IChat_RequestPublicGameOptions(This,options)	\
    (This)->lpVtbl -> RequestPublicGameOptions(This,options)

#define IChat_RequestPublicAction(This,action)	\
    (This)->lpVtbl -> RequestPublicAction(This,action)

#define IChat_RequestPrivateAction(This,users,action)	\
    (This)->lpVtbl -> RequestPrivateAction(This,users,action)

#define IChat_RequestGameStart(This,users)	\
    (This)->lpVtbl -> RequestGameStart(This,users)

#define IChat_RequestChannelTopic(This,topic)	\
    (This)->lpVtbl -> RequestChannelTopic(This,topic)

#define IChat_GetVersion(This,version)	\
    (This)->lpVtbl -> GetVersion(This,version)

#define IChat_RequestUserKick(This,user)	\
    (This)->lpVtbl -> RequestUserKick(This,user)

#define IChat_RequestUserIP(This,user)	\
    (This)->lpVtbl -> RequestUserIP(This,user)

#define IChat_GetGametypeInfo(This,gtype,icon_size,bitmap,bmp_bytes,name,URL)	\
    (This)->lpVtbl -> GetGametypeInfo(This,gtype,icon_size,bitmap,bmp_bytes,name,URL)

#define IChat_RequestFind(This,user)	\
    (This)->lpVtbl -> RequestFind(This,user)

#define IChat_RequestPage(This,user,message)	\
    (This)->lpVtbl -> RequestPage(This,user,message)

#define IChat_SetFindPage(This,findOn,pageOn)	\
    (This)->lpVtbl -> SetFindPage(This,findOn,pageOn)

#define IChat_SetSquelch(This,user,squelch)	\
    (This)->lpVtbl -> SetSquelch(This,user,squelch)

#define IChat_GetSquelch(This,user)	\
    (This)->lpVtbl -> GetSquelch(This,user)

#define IChat_SetChannelFilter(This,channelType)	\
    (This)->lpVtbl -> SetChannelFilter(This,channelType)

#define IChat_RequestGameEnd(This)	\
    (This)->lpVtbl -> RequestGameEnd(This)

#define IChat_SetLangFilter(This,onoff)	\
    (This)->lpVtbl -> SetLangFilter(This,onoff)

#define IChat_RequestChannelBan(This,name,ban)	\
    (This)->lpVtbl -> RequestChannelBan(This,name,ban)

#define IChat_GetGametypeList(This,list)	\
    (This)->lpVtbl -> GetGametypeList(This,list)

#define IChat_GetHelpURL(This,url)	\
    (This)->lpVtbl -> GetHelpURL(This,url)

#define IChat_SetProductSKU(This,SKU)	\
    (This)->lpVtbl -> SetProductSKU(This,SKU)

#define IChat_GetNick(This,num,nick,pass)	\
    (This)->lpVtbl -> GetNick(This,num,nick,pass)

#define IChat_SetNick(This,num,nick,pass,domangle)	\
    (This)->lpVtbl -> SetNick(This,num,nick,pass,domangle)

#define IChat_GetLobbyCount(This,count)	\
    (This)->lpVtbl -> GetLobbyCount(This,count)

#define IChat_RequestRawMessage(This,ircmsg)	\
    (This)->lpVtbl -> RequestRawMessage(This,ircmsg)

#define IChat_GetAttributeValue(This,attrib,value)	\
    (This)->lpVtbl -> GetAttributeValue(This,attrib,value)

#define IChat_SetAttributeValue(This,attrib,value)	\
    (This)->lpVtbl -> SetAttributeValue(This,attrib,value)

#define IChat_SetChannelExInfo(This,info)	\
    (This)->lpVtbl -> SetChannelExInfo(This,info)

#define IChat_StopAutoping(This)	\
    (This)->lpVtbl -> StopAutoping(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_PumpMessages_Proxy( 
    IChat __RPC_FAR * This);


void __RPC_STUB IChat_PumpMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestServerList_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ unsigned long SKU,
    /* [in] */ unsigned long current_version,
    /* [in] */ LPCSTR loginname,
    /* [in] */ LPCSTR password,
    /* [in] */ int timeout);


void __RPC_STUB IChat_RequestServerList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestConnection_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ Server __RPC_FAR *server,
    /* [in] */ int timeout,
    int domangle);


void __RPC_STUB IChat_RequestConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestChannelList_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ int channelType,
    /* [in] */ int autoping);


void __RPC_STUB IChat_RequestChannelList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestChannelCreate_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ Channel __RPC_FAR *channel);


void __RPC_STUB IChat_RequestChannelCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestChannelJoin_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ Channel __RPC_FAR *channel);


void __RPC_STUB IChat_RequestChannelJoin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestChannelLeave_Proxy( 
    IChat __RPC_FAR * This);


void __RPC_STUB IChat_RequestChannelLeave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestUserList_Proxy( 
    IChat __RPC_FAR * This);


void __RPC_STUB IChat_RequestUserList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestPublicMessage_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ LPCSTR message);


void __RPC_STUB IChat_RequestPublicMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestPrivateMessage_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ User __RPC_FAR *users,
    /* [in] */ LPCSTR message);


void __RPC_STUB IChat_RequestPrivateMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestLogout_Proxy( 
    IChat __RPC_FAR * This);


void __RPC_STUB IChat_RequestLogout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestPrivateGameOptions_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ User __RPC_FAR *users,
    /* [in] */ LPCSTR options);


void __RPC_STUB IChat_RequestPrivateGameOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestPublicGameOptions_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ LPCSTR options);


void __RPC_STUB IChat_RequestPublicGameOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestPublicAction_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ LPCSTR action);


void __RPC_STUB IChat_RequestPublicAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestPrivateAction_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ User __RPC_FAR *users,
    /* [in] */ LPCSTR action);


void __RPC_STUB IChat_RequestPrivateAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestGameStart_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ User __RPC_FAR *users);


void __RPC_STUB IChat_RequestGameStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestChannelTopic_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ LPCSTR topic);


void __RPC_STUB IChat_RequestChannelTopic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_GetVersion_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ unsigned long __RPC_FAR *version);


void __RPC_STUB IChat_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestUserKick_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ User __RPC_FAR *user);


void __RPC_STUB IChat_RequestUserKick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestUserIP_Proxy( 
    IChat __RPC_FAR * This,
    /* [in] */ User __RPC_FAR *user);


void __RPC_STUB IChat_RequestUserIP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_GetGametypeInfo_Proxy( 
    IChat __RPC_FAR * This,
    unsigned int gtype,
    int icon_size,
    unsigned char __RPC_FAR *__RPC_FAR *bitmap,
    int __RPC_FAR *bmp_bytes,
    LPCSTR __RPC_FAR *name,
    LPCSTR __RPC_FAR *URL);


void __RPC_STUB IChat_GetGametypeInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestFind_Proxy( 
    IChat __RPC_FAR * This,
    User __RPC_FAR *user);


void __RPC_STUB IChat_RequestFind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestPage_Proxy( 
    IChat __RPC_FAR * This,
    User __RPC_FAR *user,
    LPCSTR message);


void __RPC_STUB IChat_RequestPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_SetFindPage_Proxy( 
    IChat __RPC_FAR * This,
    int findOn,
    int pageOn);


void __RPC_STUB IChat_SetFindPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_SetSquelch_Proxy( 
    IChat __RPC_FAR * This,
    User __RPC_FAR *user,
    int squelch);


void __RPC_STUB IChat_SetSquelch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_GetSquelch_Proxy( 
    IChat __RPC_FAR * This,
    User __RPC_FAR *user);


void __RPC_STUB IChat_GetSquelch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_SetChannelFilter_Proxy( 
    IChat __RPC_FAR * This,
    int channelType);


void __RPC_STUB IChat_SetChannelFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestGameEnd_Proxy( 
    IChat __RPC_FAR * This);


void __RPC_STUB IChat_RequestGameEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_SetLangFilter_Proxy( 
    IChat __RPC_FAR * This,
    int onoff);


void __RPC_STUB IChat_SetLangFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestChannelBan_Proxy( 
    IChat __RPC_FAR * This,
    LPCSTR name,
    int ban);


void __RPC_STUB IChat_RequestChannelBan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_GetGametypeList_Proxy( 
    IChat __RPC_FAR * This,
    LPCSTR __RPC_FAR *list);


void __RPC_STUB IChat_GetGametypeList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_GetHelpURL_Proxy( 
    IChat __RPC_FAR * This,
    LPCSTR __RPC_FAR *url);


void __RPC_STUB IChat_GetHelpURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_SetProductSKU_Proxy( 
    IChat __RPC_FAR * This,
    unsigned long SKU);


void __RPC_STUB IChat_SetProductSKU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_GetNick_Proxy( 
    IChat __RPC_FAR * This,
    int num,
    LPCSTR __RPC_FAR *nick,
    LPCSTR __RPC_FAR *pass);


void __RPC_STUB IChat_GetNick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_SetNick_Proxy( 
    IChat __RPC_FAR * This,
    int num,
    LPCSTR nick,
    LPCSTR pass,
    int domangle);


void __RPC_STUB IChat_SetNick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_GetLobbyCount_Proxy( 
    IChat __RPC_FAR * This,
    int __RPC_FAR *count);


void __RPC_STUB IChat_GetLobbyCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_RequestRawMessage_Proxy( 
    IChat __RPC_FAR * This,
    LPCSTR ircmsg);


void __RPC_STUB IChat_RequestRawMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_GetAttributeValue_Proxy( 
    IChat __RPC_FAR * This,
    LPCSTR attrib,
    LPCSTR __RPC_FAR *value);


void __RPC_STUB IChat_GetAttributeValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_SetAttributeValue_Proxy( 
    IChat __RPC_FAR * This,
    LPCSTR attrib,
    LPCSTR value);


void __RPC_STUB IChat_SetAttributeValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_SetChannelExInfo_Proxy( 
    IChat __RPC_FAR * This,
    LPCSTR info);


void __RPC_STUB IChat_SetChannelExInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat_StopAutoping_Proxy( 
    IChat __RPC_FAR * This);


void __RPC_STUB IChat_StopAutoping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChat_INTERFACE_DEFINED__ */


#ifndef __IChatEvent_INTERFACE_DEFINED__
#define __IChatEvent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IChatEvent
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 



EXTERN_C const IID IID_IChatEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("4DD3BAF6-7579-11D1-B1C6-006097176556")
    IChatEvent : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnServerList( 
            /* [in] */ HRESULT res,
            /* [in] */ Server __RPC_FAR *servers) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUpdateList( 
            /* [in] */ HRESULT res,
            /* [in] */ Update __RPC_FAR *updates) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnServerError( 
            /* [in] */ HRESULT res,
            /* [in] */ LPCSTR ircmsg) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnConnection( 
            /* [in] */ HRESULT res,
            /* [in] */ LPCSTR motd) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMessageOfTheDay( 
            /* [in] */ HRESULT res,
            /* [in] */ LPCSTR motd) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelList( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channels) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelCreate( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelJoin( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelLeave( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelTopic( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ LPCSTR topic) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPrivateAction( 
            /* [in] */ HRESULT res,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR action) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPublicAction( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            User __RPC_FAR *user,
            /* [in] */ LPCSTR action) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUserList( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *users) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPublicMessage( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPrivateMessage( 
            /* [in] */ HRESULT res,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnSystemMessage( 
            /* [in] */ HRESULT res,
            /* [in] */ LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnNetStatus( 
            /* [in] */ HRESULT res) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLogout( 
            /* [in] */ HRESULT status,
            /* [in] */ User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPrivateGameOptions( 
            /* [in] */ HRESULT res,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR options) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPublicGameOptions( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR options) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnGameStart( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *users,
            /* [in] */ int gameid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUserKick( 
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *kicked,
            /* [in] */ User __RPC_FAR *kicker) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUserIP( 
            /* [in] */ HRESULT res,
            /* [in] */ User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnFind( 
            HRESULT res,
            Channel __RPC_FAR *chan) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPageSend( 
            HRESULT res) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPaged( 
            HRESULT res,
            User __RPC_FAR *user,
            LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnServerBannedYou( 
            HRESULT res,
            time_t bannedTill) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUserFlags( 
            HRESULT res,
            LPCSTR name,
            unsigned int flags,
            unsigned int mask) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelBan( 
            HRESULT res,
            LPCSTR name,
            int banned) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChatEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChatEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChatEvent __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnServerList )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Server __RPC_FAR *servers);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnUpdateList )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Update __RPC_FAR *updates);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnServerError )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ LPCSTR ircmsg);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnConnection )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ LPCSTR motd);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnMessageOfTheDay )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ LPCSTR motd);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelList )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channels);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelCreate )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelJoin )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelLeave )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelTopic )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ LPCSTR topic);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPrivateAction )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR action);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPublicAction )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            User __RPC_FAR *user,
            /* [in] */ LPCSTR action);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnUserList )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *users);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPublicMessage )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPrivateMessage )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnSystemMessage )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnNetStatus )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLogout )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT status,
            /* [in] */ User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPrivateGameOptions )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR options);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPublicGameOptions )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *user,
            /* [in] */ LPCSTR options);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnGameStart )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *users,
            /* [in] */ int gameid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnUserKick )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ Channel __RPC_FAR *channel,
            /* [in] */ User __RPC_FAR *kicked,
            /* [in] */ User __RPC_FAR *kicker);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnUserIP )( 
            IChatEvent __RPC_FAR * This,
            /* [in] */ HRESULT res,
            /* [in] */ User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnFind )( 
            IChatEvent __RPC_FAR * This,
            HRESULT res,
            Channel __RPC_FAR *chan);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPageSend )( 
            IChatEvent __RPC_FAR * This,
            HRESULT res);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPaged )( 
            IChatEvent __RPC_FAR * This,
            HRESULT res,
            User __RPC_FAR *user,
            LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnServerBannedYou )( 
            IChatEvent __RPC_FAR * This,
            HRESULT res,
            time_t bannedTill);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnUserFlags )( 
            IChatEvent __RPC_FAR * This,
            HRESULT res,
            LPCSTR name,
            unsigned int flags,
            unsigned int mask);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelBan )( 
            IChatEvent __RPC_FAR * This,
            HRESULT res,
            LPCSTR name,
            int banned);
        
        END_INTERFACE
    } IChatEventVtbl;

    interface IChatEvent
    {
        CONST_VTBL struct IChatEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChatEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChatEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChatEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChatEvent_OnServerList(This,res,servers)	\
    (This)->lpVtbl -> OnServerList(This,res,servers)

#define IChatEvent_OnUpdateList(This,res,updates)	\
    (This)->lpVtbl -> OnUpdateList(This,res,updates)

#define IChatEvent_OnServerError(This,res,ircmsg)	\
    (This)->lpVtbl -> OnServerError(This,res,ircmsg)

#define IChatEvent_OnConnection(This,res,motd)	\
    (This)->lpVtbl -> OnConnection(This,res,motd)

#define IChatEvent_OnMessageOfTheDay(This,res,motd)	\
    (This)->lpVtbl -> OnMessageOfTheDay(This,res,motd)

#define IChatEvent_OnChannelList(This,res,channels)	\
    (This)->lpVtbl -> OnChannelList(This,res,channels)

#define IChatEvent_OnChannelCreate(This,res,channel)	\
    (This)->lpVtbl -> OnChannelCreate(This,res,channel)

#define IChatEvent_OnChannelJoin(This,res,channel,user)	\
    (This)->lpVtbl -> OnChannelJoin(This,res,channel,user)

#define IChatEvent_OnChannelLeave(This,res,channel,user)	\
    (This)->lpVtbl -> OnChannelLeave(This,res,channel,user)

#define IChatEvent_OnChannelTopic(This,res,channel,topic)	\
    (This)->lpVtbl -> OnChannelTopic(This,res,channel,topic)

#define IChatEvent_OnPrivateAction(This,res,user,action)	\
    (This)->lpVtbl -> OnPrivateAction(This,res,user,action)

#define IChatEvent_OnPublicAction(This,res,channel,user,action)	\
    (This)->lpVtbl -> OnPublicAction(This,res,channel,user,action)

#define IChatEvent_OnUserList(This,res,channel,users)	\
    (This)->lpVtbl -> OnUserList(This,res,channel,users)

#define IChatEvent_OnPublicMessage(This,res,channel,user,message)	\
    (This)->lpVtbl -> OnPublicMessage(This,res,channel,user,message)

#define IChatEvent_OnPrivateMessage(This,res,user,message)	\
    (This)->lpVtbl -> OnPrivateMessage(This,res,user,message)

#define IChatEvent_OnSystemMessage(This,res,message)	\
    (This)->lpVtbl -> OnSystemMessage(This,res,message)

#define IChatEvent_OnNetStatus(This,res)	\
    (This)->lpVtbl -> OnNetStatus(This,res)

#define IChatEvent_OnLogout(This,status,user)	\
    (This)->lpVtbl -> OnLogout(This,status,user)

#define IChatEvent_OnPrivateGameOptions(This,res,user,options)	\
    (This)->lpVtbl -> OnPrivateGameOptions(This,res,user,options)

#define IChatEvent_OnPublicGameOptions(This,res,channel,user,options)	\
    (This)->lpVtbl -> OnPublicGameOptions(This,res,channel,user,options)

#define IChatEvent_OnGameStart(This,res,channel,users,gameid)	\
    (This)->lpVtbl -> OnGameStart(This,res,channel,users,gameid)

#define IChatEvent_OnUserKick(This,res,channel,kicked,kicker)	\
    (This)->lpVtbl -> OnUserKick(This,res,channel,kicked,kicker)

#define IChatEvent_OnUserIP(This,res,user)	\
    (This)->lpVtbl -> OnUserIP(This,res,user)

#define IChatEvent_OnFind(This,res,chan)	\
    (This)->lpVtbl -> OnFind(This,res,chan)

#define IChatEvent_OnPageSend(This,res)	\
    (This)->lpVtbl -> OnPageSend(This,res)

#define IChatEvent_OnPaged(This,res,user,message)	\
    (This)->lpVtbl -> OnPaged(This,res,user,message)

#define IChatEvent_OnServerBannedYou(This,res,bannedTill)	\
    (This)->lpVtbl -> OnServerBannedYou(This,res,bannedTill)

#define IChatEvent_OnUserFlags(This,res,name,flags,mask)	\
    (This)->lpVtbl -> OnUserFlags(This,res,name,flags,mask)

#define IChatEvent_OnChannelBan(This,res,name,banned)	\
    (This)->lpVtbl -> OnChannelBan(This,res,name,banned)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnServerList_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Server __RPC_FAR *servers);


void __RPC_STUB IChatEvent_OnServerList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnUpdateList_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Update __RPC_FAR *updates);


void __RPC_STUB IChatEvent_OnUpdateList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnServerError_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ LPCSTR ircmsg);


void __RPC_STUB IChatEvent_OnServerError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnConnection_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ LPCSTR motd);


void __RPC_STUB IChatEvent_OnConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnMessageOfTheDay_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ LPCSTR motd);


void __RPC_STUB IChatEvent_OnMessageOfTheDay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnChannelList_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channels);


void __RPC_STUB IChatEvent_OnChannelList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnChannelCreate_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel);


void __RPC_STUB IChatEvent_OnChannelCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnChannelJoin_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    /* [in] */ User __RPC_FAR *user);


void __RPC_STUB IChatEvent_OnChannelJoin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnChannelLeave_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    /* [in] */ User __RPC_FAR *user);


void __RPC_STUB IChatEvent_OnChannelLeave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnChannelTopic_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    /* [in] */ LPCSTR topic);


void __RPC_STUB IChatEvent_OnChannelTopic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnPrivateAction_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ User __RPC_FAR *user,
    /* [in] */ LPCSTR action);


void __RPC_STUB IChatEvent_OnPrivateAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnPublicAction_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    User __RPC_FAR *user,
    /* [in] */ LPCSTR action);


void __RPC_STUB IChatEvent_OnPublicAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnUserList_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    /* [in] */ User __RPC_FAR *users);


void __RPC_STUB IChatEvent_OnUserList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnPublicMessage_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    /* [in] */ User __RPC_FAR *user,
    /* [in] */ LPCSTR message);


void __RPC_STUB IChatEvent_OnPublicMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnPrivateMessage_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ User __RPC_FAR *user,
    /* [in] */ LPCSTR message);


void __RPC_STUB IChatEvent_OnPrivateMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnSystemMessage_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ LPCSTR message);


void __RPC_STUB IChatEvent_OnSystemMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnNetStatus_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res);


void __RPC_STUB IChatEvent_OnNetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnLogout_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT status,
    /* [in] */ User __RPC_FAR *user);


void __RPC_STUB IChatEvent_OnLogout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnPrivateGameOptions_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ User __RPC_FAR *user,
    /* [in] */ LPCSTR options);


void __RPC_STUB IChatEvent_OnPrivateGameOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnPublicGameOptions_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    /* [in] */ User __RPC_FAR *user,
    /* [in] */ LPCSTR options);


void __RPC_STUB IChatEvent_OnPublicGameOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnGameStart_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    /* [in] */ User __RPC_FAR *users,
    /* [in] */ int gameid);


void __RPC_STUB IChatEvent_OnGameStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnUserKick_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ Channel __RPC_FAR *channel,
    /* [in] */ User __RPC_FAR *kicked,
    /* [in] */ User __RPC_FAR *kicker);


void __RPC_STUB IChatEvent_OnUserKick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnUserIP_Proxy( 
    IChatEvent __RPC_FAR * This,
    /* [in] */ HRESULT res,
    /* [in] */ User __RPC_FAR *user);


void __RPC_STUB IChatEvent_OnUserIP_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnFind_Proxy( 
    IChatEvent __RPC_FAR * This,
    HRESULT res,
    Channel __RPC_FAR *chan);


void __RPC_STUB IChatEvent_OnFind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnPageSend_Proxy( 
    IChatEvent __RPC_FAR * This,
    HRESULT res);


void __RPC_STUB IChatEvent_OnPageSend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnPaged_Proxy( 
    IChatEvent __RPC_FAR * This,
    HRESULT res,
    User __RPC_FAR *user,
    LPCSTR message);


void __RPC_STUB IChatEvent_OnPaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnServerBannedYou_Proxy( 
    IChatEvent __RPC_FAR * This,
    HRESULT res,
    time_t bannedTill);


void __RPC_STUB IChatEvent_OnServerBannedYou_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnUserFlags_Proxy( 
    IChatEvent __RPC_FAR * This,
    HRESULT res,
    LPCSTR name,
    unsigned int flags,
    unsigned int mask);


void __RPC_STUB IChatEvent_OnUserFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChatEvent_OnChannelBan_Proxy( 
    IChatEvent __RPC_FAR * This,
    HRESULT res,
    LPCSTR name,
    int banned);


void __RPC_STUB IChatEvent_OnChannelBan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChatEvent_INTERFACE_DEFINED__ */


#ifndef __IDownload_INTERFACE_DEFINED__
#define __IDownload_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDownload
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [unique][helpstring][dual][uuid][object] */ 



EXTERN_C const IID IID_IDownload;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("0BF5FCEB-9F03-11D1-9DC7-006097C54321")
    IDownload : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadFile( 
            LPCSTR server,
            LPCSTR login,
            LPCSTR password,
            LPCSTR file,
            LPCSTR localfile,
            LPCSTR regkey) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Abort( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PumpMessages( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDownloadVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDownload __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDownload __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDownload __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DownloadFile )( 
            IDownload __RPC_FAR * This,
            LPCSTR server,
            LPCSTR login,
            LPCSTR password,
            LPCSTR file,
            LPCSTR localfile,
            LPCSTR regkey);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Abort )( 
            IDownload __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PumpMessages )( 
            IDownload __RPC_FAR * This);
        
        END_INTERFACE
    } IDownloadVtbl;

    interface IDownload
    {
        CONST_VTBL struct IDownloadVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDownload_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDownload_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDownload_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDownload_DownloadFile(This,server,login,password,file,localfile,regkey)	\
    (This)->lpVtbl -> DownloadFile(This,server,login,password,file,localfile,regkey)

#define IDownload_Abort(This)	\
    (This)->lpVtbl -> Abort(This)

#define IDownload_PumpMessages(This)	\
    (This)->lpVtbl -> PumpMessages(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDownload_DownloadFile_Proxy( 
    IDownload __RPC_FAR * This,
    LPCSTR server,
    LPCSTR login,
    LPCSTR password,
    LPCSTR file,
    LPCSTR localfile,
    LPCSTR regkey);


void __RPC_STUB IDownload_DownloadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDownload_Abort_Proxy( 
    IDownload __RPC_FAR * This);


void __RPC_STUB IDownload_Abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDownload_PumpMessages_Proxy( 
    IDownload __RPC_FAR * This);


void __RPC_STUB IDownload_PumpMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDownload_INTERFACE_DEFINED__ */


#ifndef __IDownloadEvent_INTERFACE_DEFINED__
#define __IDownloadEvent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDownloadEvent
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 



EXTERN_C const IID IID_IDownloadEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("6869E99D-9FB4-11D1-9DC8-006097C54321")
    IDownloadEvent : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnEnd( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnError( 
            int error) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnProgressUpdate( 
            int bytesread,
            int totalsize,
            int timetaken,
            int timeleft) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnQueryResume( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnStatusUpdate( 
            int status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDownloadEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDownloadEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDownloadEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDownloadEvent __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnEnd )( 
            IDownloadEvent __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnError )( 
            IDownloadEvent __RPC_FAR * This,
            int error);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnProgressUpdate )( 
            IDownloadEvent __RPC_FAR * This,
            int bytesread,
            int totalsize,
            int timetaken,
            int timeleft);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnQueryResume )( 
            IDownloadEvent __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnStatusUpdate )( 
            IDownloadEvent __RPC_FAR * This,
            int status);
        
        END_INTERFACE
    } IDownloadEventVtbl;

    interface IDownloadEvent
    {
        CONST_VTBL struct IDownloadEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDownloadEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDownloadEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDownloadEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDownloadEvent_OnEnd(This)	\
    (This)->lpVtbl -> OnEnd(This)

#define IDownloadEvent_OnError(This,error)	\
    (This)->lpVtbl -> OnError(This,error)

#define IDownloadEvent_OnProgressUpdate(This,bytesread,totalsize,timetaken,timeleft)	\
    (This)->lpVtbl -> OnProgressUpdate(This,bytesread,totalsize,timetaken,timeleft)

#define IDownloadEvent_OnQueryResume(This)	\
    (This)->lpVtbl -> OnQueryResume(This)

#define IDownloadEvent_OnStatusUpdate(This,status)	\
    (This)->lpVtbl -> OnStatusUpdate(This,status)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDownloadEvent_OnEnd_Proxy( 
    IDownloadEvent __RPC_FAR * This);


void __RPC_STUB IDownloadEvent_OnEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDownloadEvent_OnError_Proxy( 
    IDownloadEvent __RPC_FAR * This,
    int error);


void __RPC_STUB IDownloadEvent_OnError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDownloadEvent_OnProgressUpdate_Proxy( 
    IDownloadEvent __RPC_FAR * This,
    int bytesread,
    int totalsize,
    int timetaken,
    int timeleft);


void __RPC_STUB IDownloadEvent_OnProgressUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDownloadEvent_OnQueryResume_Proxy( 
    IDownloadEvent __RPC_FAR * This);


void __RPC_STUB IDownloadEvent_OnQueryResume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDownloadEvent_OnStatusUpdate_Proxy( 
    IDownloadEvent __RPC_FAR * This,
    int status);


void __RPC_STUB IDownloadEvent_OnStatusUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDownloadEvent_INTERFACE_DEFINED__ */


#ifndef __INetUtil_INTERFACE_DEFINED__
#define __INetUtil_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: INetUtil
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 



EXTERN_C const IID IID_INetUtil;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("B832B0AA-A7D3-11D1-97C3-00609706FA0C")
    INetUtil : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestGameresSend( 
            LPCSTR host,
            int port,
            unsigned char __RPC_FAR *data,
            int length) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestLadderSearch( 
            LPCSTR host,
            int port,
            LPCSTR key,
            unsigned long SKU,
            int team,
            int cond,
            int sort,
            int number,
            int leading) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestLadderList( 
            LPCSTR host,
            int port,
            LPCSTR keys,
            unsigned long SKU,
            int team,
            int cond,
            int sort) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RequestPing( 
            LPCSTR host,
            int timeout,
            int __RPC_FAR *handle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PumpMessages( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAvgPing( 
            unsigned long ip,
            int __RPC_FAR *avg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetUtilVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INetUtil __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INetUtil __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INetUtil __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestGameresSend )( 
            INetUtil __RPC_FAR * This,
            LPCSTR host,
            int port,
            unsigned char __RPC_FAR *data,
            int length);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestLadderSearch )( 
            INetUtil __RPC_FAR * This,
            LPCSTR host,
            int port,
            LPCSTR key,
            unsigned long SKU,
            int team,
            int cond,
            int sort,
            int number,
            int leading);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestLadderList )( 
            INetUtil __RPC_FAR * This,
            LPCSTR host,
            int port,
            LPCSTR keys,
            unsigned long SKU,
            int team,
            int cond,
            int sort);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestPing )( 
            INetUtil __RPC_FAR * This,
            LPCSTR host,
            int timeout,
            int __RPC_FAR *handle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PumpMessages )( 
            INetUtil __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAvgPing )( 
            INetUtil __RPC_FAR * This,
            unsigned long ip,
            int __RPC_FAR *avg);
        
        END_INTERFACE
    } INetUtilVtbl;

    interface INetUtil
    {
        CONST_VTBL struct INetUtilVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetUtil_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetUtil_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetUtil_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetUtil_RequestGameresSend(This,host,port,data,length)	\
    (This)->lpVtbl -> RequestGameresSend(This,host,port,data,length)

#define INetUtil_RequestLadderSearch(This,host,port,key,SKU,team,cond,sort,number,leading)	\
    (This)->lpVtbl -> RequestLadderSearch(This,host,port,key,SKU,team,cond,sort,number,leading)

#define INetUtil_RequestLadderList(This,host,port,keys,SKU,team,cond,sort)	\
    (This)->lpVtbl -> RequestLadderList(This,host,port,keys,SKU,team,cond,sort)

#define INetUtil_RequestPing(This,host,timeout,handle)	\
    (This)->lpVtbl -> RequestPing(This,host,timeout,handle)

#define INetUtil_PumpMessages(This)	\
    (This)->lpVtbl -> PumpMessages(This)

#define INetUtil_GetAvgPing(This,ip,avg)	\
    (This)->lpVtbl -> GetAvgPing(This,ip,avg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetUtil_RequestGameresSend_Proxy( 
    INetUtil __RPC_FAR * This,
    LPCSTR host,
    int port,
    unsigned char __RPC_FAR *data,
    int length);


void __RPC_STUB INetUtil_RequestGameresSend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetUtil_RequestLadderSearch_Proxy( 
    INetUtil __RPC_FAR * This,
    LPCSTR host,
    int port,
    LPCSTR key,
    unsigned long SKU,
    int team,
    int cond,
    int sort,
    int number,
    int leading);


void __RPC_STUB INetUtil_RequestLadderSearch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetUtil_RequestLadderList_Proxy( 
    INetUtil __RPC_FAR * This,
    LPCSTR host,
    int port,
    LPCSTR keys,
    unsigned long SKU,
    int team,
    int cond,
    int sort);


void __RPC_STUB INetUtil_RequestLadderList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetUtil_RequestPing_Proxy( 
    INetUtil __RPC_FAR * This,
    LPCSTR host,
    int timeout,
    int __RPC_FAR *handle);


void __RPC_STUB INetUtil_RequestPing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetUtil_PumpMessages_Proxy( 
    INetUtil __RPC_FAR * This);


void __RPC_STUB INetUtil_PumpMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE INetUtil_GetAvgPing_Proxy( 
    INetUtil __RPC_FAR * This,
    unsigned long ip,
    int __RPC_FAR *avg);


void __RPC_STUB INetUtil_GetAvgPing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetUtil_INTERFACE_DEFINED__ */


#ifndef __INetUtilEvent_INTERFACE_DEFINED__
#define __INetUtilEvent_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: INetUtilEvent
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 



EXTERN_C const IID IID_INetUtilEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("B832B0AC-A7D3-11D1-97C3-00609706FA0C")
    INetUtilEvent : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnPing( 
            HRESULT res,
            int time,
            unsigned long ip,
            int handle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnLadderList( 
            HRESULT res,
            /* [in] */ Ladder __RPC_FAR *list,
            int totalCount,
            long timeStamp,
            int keyRung) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnGameresSent( 
            HRESULT res) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetUtilEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INetUtilEvent __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INetUtilEvent __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INetUtilEvent __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnPing )( 
            INetUtilEvent __RPC_FAR * This,
            HRESULT res,
            int time,
            unsigned long ip,
            int handle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLadderList )( 
            INetUtilEvent __RPC_FAR * This,
            HRESULT res,
            /* [in] */ Ladder __RPC_FAR *list,
            int totalCount,
            long timeStamp,
            int keyRung);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnGameresSent )( 
            INetUtilEvent __RPC_FAR * This,
            HRESULT res);
        
        END_INTERFACE
    } INetUtilEventVtbl;

    interface INetUtilEvent
    {
        CONST_VTBL struct INetUtilEventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetUtilEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetUtilEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetUtilEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetUtilEvent_OnPing(This,res,time,ip,handle)	\
    (This)->lpVtbl -> OnPing(This,res,time,ip,handle)

#define INetUtilEvent_OnLadderList(This,res,list,totalCount,timeStamp,keyRung)	\
    (This)->lpVtbl -> OnLadderList(This,res,list,totalCount,timeStamp,keyRung)

#define INetUtilEvent_OnGameresSent(This,res)	\
    (This)->lpVtbl -> OnGameresSent(This,res)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetUtilEvent_OnPing_Proxy( 
    INetUtilEvent __RPC_FAR * This,
    HRESULT res,
    int time,
    unsigned long ip,
    int handle);


void __RPC_STUB INetUtilEvent_OnPing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetUtilEvent_OnLadderList_Proxy( 
    INetUtilEvent __RPC_FAR * This,
    HRESULT res,
    /* [in] */ Ladder __RPC_FAR *list,
    int totalCount,
    long timeStamp,
    int keyRung);


void __RPC_STUB INetUtilEvent_OnLadderList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetUtilEvent_OnGameresSent_Proxy( 
    INetUtilEvent __RPC_FAR * This,
    HRESULT res);


void __RPC_STUB INetUtilEvent_OnGameresSent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetUtilEvent_INTERFACE_DEFINED__ */


#ifndef __IChat2_INTERFACE_DEFINED__
#define __IChat2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IChat2
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 


typedef unsigned long GID;


enum GTYPE_
    {	SERVER	= 0,
	CHANNEL	= 1,
	CLIENT	= 2
    };
typedef enum GTYPE_ GTYPE;


enum CHAN_CTYPE_
    {	ALLEXIT	= 0,
	CREATOREXIT	= 1,
	CLOSEC	= 2
    };
typedef enum CHAN_CTYPE_ CHAN_CTYPE;


EXTERN_C const IID IID_IChat2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8B938190-EF3F-11D1-9808-00609706FA0C")
    IChat2 : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PumpMessages( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestConnection( 
            Server __RPC_FAR *server,
            int timeout) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestMessage( 
            GID who,
            LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTypeFromGID( 
            GID id,
            GTYPE __RPC_FAR *type) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelList( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelJoin( 
            LPCSTR name) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelLeave( 
            Channel __RPC_FAR *chan) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestUserList( 
            Channel __RPC_FAR *chan) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestLogout( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestChannelCreate( 
            Channel __RPC_FAR *chan) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RequestRawCmd( 
            LPCSTR cmd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChat2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChat2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChat2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChat2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PumpMessages )( 
            IChat2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestConnection )( 
            IChat2 __RPC_FAR * This,
            Server __RPC_FAR *server,
            int timeout);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestMessage )( 
            IChat2 __RPC_FAR * This,
            GID who,
            LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeFromGID )( 
            IChat2 __RPC_FAR * This,
            GID id,
            GTYPE __RPC_FAR *type);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelList )( 
            IChat2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelJoin )( 
            IChat2 __RPC_FAR * This,
            LPCSTR name);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelLeave )( 
            IChat2 __RPC_FAR * This,
            Channel __RPC_FAR *chan);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestUserList )( 
            IChat2 __RPC_FAR * This,
            Channel __RPC_FAR *chan);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestLogout )( 
            IChat2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestChannelCreate )( 
            IChat2 __RPC_FAR * This,
            Channel __RPC_FAR *chan);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestRawCmd )( 
            IChat2 __RPC_FAR * This,
            LPCSTR cmd);
        
        END_INTERFACE
    } IChat2Vtbl;

    interface IChat2
    {
        CONST_VTBL struct IChat2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChat2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChat2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChat2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChat2_PumpMessages(This)	\
    (This)->lpVtbl -> PumpMessages(This)

#define IChat2_RequestConnection(This,server,timeout)	\
    (This)->lpVtbl -> RequestConnection(This,server,timeout)

#define IChat2_RequestMessage(This,who,message)	\
    (This)->lpVtbl -> RequestMessage(This,who,message)

#define IChat2_GetTypeFromGID(This,id,type)	\
    (This)->lpVtbl -> GetTypeFromGID(This,id,type)

#define IChat2_RequestChannelList(This)	\
    (This)->lpVtbl -> RequestChannelList(This)

#define IChat2_RequestChannelJoin(This,name)	\
    (This)->lpVtbl -> RequestChannelJoin(This,name)

#define IChat2_RequestChannelLeave(This,chan)	\
    (This)->lpVtbl -> RequestChannelLeave(This,chan)

#define IChat2_RequestUserList(This,chan)	\
    (This)->lpVtbl -> RequestUserList(This,chan)

#define IChat2_RequestLogout(This)	\
    (This)->lpVtbl -> RequestLogout(This)

#define IChat2_RequestChannelCreate(This,chan)	\
    (This)->lpVtbl -> RequestChannelCreate(This,chan)

#define IChat2_RequestRawCmd(This,cmd)	\
    (This)->lpVtbl -> RequestRawCmd(This,cmd)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_PumpMessages_Proxy( 
    IChat2 __RPC_FAR * This);


void __RPC_STUB IChat2_PumpMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestConnection_Proxy( 
    IChat2 __RPC_FAR * This,
    Server __RPC_FAR *server,
    int timeout);


void __RPC_STUB IChat2_RequestConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestMessage_Proxy( 
    IChat2 __RPC_FAR * This,
    GID who,
    LPCSTR message);


void __RPC_STUB IChat2_RequestMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_GetTypeFromGID_Proxy( 
    IChat2 __RPC_FAR * This,
    GID id,
    GTYPE __RPC_FAR *type);


void __RPC_STUB IChat2_GetTypeFromGID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestChannelList_Proxy( 
    IChat2 __RPC_FAR * This);


void __RPC_STUB IChat2_RequestChannelList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestChannelJoin_Proxy( 
    IChat2 __RPC_FAR * This,
    LPCSTR name);


void __RPC_STUB IChat2_RequestChannelJoin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestChannelLeave_Proxy( 
    IChat2 __RPC_FAR * This,
    Channel __RPC_FAR *chan);


void __RPC_STUB IChat2_RequestChannelLeave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestUserList_Proxy( 
    IChat2 __RPC_FAR * This,
    Channel __RPC_FAR *chan);


void __RPC_STUB IChat2_RequestUserList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestLogout_Proxy( 
    IChat2 __RPC_FAR * This);


void __RPC_STUB IChat2_RequestLogout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestChannelCreate_Proxy( 
    IChat2 __RPC_FAR * This,
    Channel __RPC_FAR *chan);


void __RPC_STUB IChat2_RequestChannelCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2_RequestRawCmd_Proxy( 
    IChat2 __RPC_FAR * This,
    LPCSTR cmd);


void __RPC_STUB IChat2_RequestRawCmd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChat2_INTERFACE_DEFINED__ */


#ifndef __IChat2Event_INTERFACE_DEFINED__
#define __IChat2Event_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IChat2Event
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [object][unique][helpstring][uuid] */ 



EXTERN_C const IID IID_IChat2Event;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("8B938192-EF3F-11D1-9808-00609706FA0C")
    IChat2Event : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnNetStatus( 
            HRESULT res) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnMessage( 
            HRESULT res,
            User __RPC_FAR *user,
            LPCSTR message) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelList( 
            HRESULT res,
            Channel __RPC_FAR *list) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelJoin( 
            HRESULT res,
            Channel __RPC_FAR *chan,
            User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnLogin( 
            HRESULT res) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUserList( 
            HRESULT res,
            Channel __RPC_FAR *chan,
            User __RPC_FAR *users) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelLeave( 
            HRESULT res,
            Channel __RPC_FAR *chan,
            User __RPC_FAR *user) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChannelCreate( 
            HRESULT res,
            Channel __RPC_FAR *chan) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnUnknownLine( 
            HRESULT res,
            LPCSTR line) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChat2EventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChat2Event __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChat2Event __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChat2Event __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnNetStatus )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnMessage )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res,
            User __RPC_FAR *user,
            LPCSTR message);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelList )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res,
            Channel __RPC_FAR *list);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelJoin )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res,
            Channel __RPC_FAR *chan,
            User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnLogin )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnUserList )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res,
            Channel __RPC_FAR *chan,
            User __RPC_FAR *users);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelLeave )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res,
            Channel __RPC_FAR *chan,
            User __RPC_FAR *user);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnChannelCreate )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res,
            Channel __RPC_FAR *chan);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnUnknownLine )( 
            IChat2Event __RPC_FAR * This,
            HRESULT res,
            LPCSTR line);
        
        END_INTERFACE
    } IChat2EventVtbl;

    interface IChat2Event
    {
        CONST_VTBL struct IChat2EventVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChat2Event_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChat2Event_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChat2Event_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChat2Event_OnNetStatus(This,res)	\
    (This)->lpVtbl -> OnNetStatus(This,res)

#define IChat2Event_OnMessage(This,res,user,message)	\
    (This)->lpVtbl -> OnMessage(This,res,user,message)

#define IChat2Event_OnChannelList(This,res,list)	\
    (This)->lpVtbl -> OnChannelList(This,res,list)

#define IChat2Event_OnChannelJoin(This,res,chan,user)	\
    (This)->lpVtbl -> OnChannelJoin(This,res,chan,user)

#define IChat2Event_OnLogin(This,res)	\
    (This)->lpVtbl -> OnLogin(This,res)

#define IChat2Event_OnUserList(This,res,chan,users)	\
    (This)->lpVtbl -> OnUserList(This,res,chan,users)

#define IChat2Event_OnChannelLeave(This,res,chan,user)	\
    (This)->lpVtbl -> OnChannelLeave(This,res,chan,user)

#define IChat2Event_OnChannelCreate(This,res,chan)	\
    (This)->lpVtbl -> OnChannelCreate(This,res,chan)

#define IChat2Event_OnUnknownLine(This,res,line)	\
    (This)->lpVtbl -> OnUnknownLine(This,res,line)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnNetStatus_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res);


void __RPC_STUB IChat2Event_OnNetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnMessage_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res,
    User __RPC_FAR *user,
    LPCSTR message);


void __RPC_STUB IChat2Event_OnMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnChannelList_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res,
    Channel __RPC_FAR *list);


void __RPC_STUB IChat2Event_OnChannelList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnChannelJoin_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res,
    Channel __RPC_FAR *chan,
    User __RPC_FAR *user);


void __RPC_STUB IChat2Event_OnChannelJoin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnLogin_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res);


void __RPC_STUB IChat2Event_OnLogin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnUserList_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res,
    Channel __RPC_FAR *chan,
    User __RPC_FAR *users);


void __RPC_STUB IChat2Event_OnUserList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnChannelLeave_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res,
    Channel __RPC_FAR *chan,
    User __RPC_FAR *user);


void __RPC_STUB IChat2Event_OnChannelLeave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnChannelCreate_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res,
    Channel __RPC_FAR *chan);


void __RPC_STUB IChat2Event_OnChannelCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IChat2Event_OnUnknownLine_Proxy( 
    IChat2Event __RPC_FAR * This,
    HRESULT res,
    LPCSTR line);


void __RPC_STUB IChat2Event_OnUnknownLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IChat2Event_INTERFACE_DEFINED__ */



#ifndef __WOLAPILib_LIBRARY_DEFINED__
#define __WOLAPILib_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: WOLAPILib
 * at Wed Jul 29 16:25:34 1998
 * using MIDL 3.01.75
 ****************************************/
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_WOLAPILib;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_RTPatcher;

class DECLSPEC_UUID("925CDEDF-71B9-11D1-B1C5-006097176556")
RTPatcher;
#endif

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_Chat;

class DECLSPEC_UUID("4DD3BAF5-7579-11D1-B1C6-006097176556")
Chat;
#endif

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_Download;

class DECLSPEC_UUID("BF6EA206-9E55-11D1-9DC6-006097C54321")
Download;
#endif

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_NetUtil;

class DECLSPEC_UUID("B832B0AB-A7D3-11D1-97C3-00609706FA0C")
NetUtil;
#endif

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_Chat2;

class DECLSPEC_UUID("8B938191-EF3F-11D1-9808-00609706FA0C")
Chat2;
#endif
#endif /* __WOLAPILib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
