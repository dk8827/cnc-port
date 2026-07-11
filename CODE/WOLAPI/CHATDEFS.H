/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef CHATDEFS_HEADER
#define CHATDEFS_HEADER

//
// Response errors (Sent as arguments to the OnFoo calls)
//

// Your nick is still logged into chat
#define CHAT_E_NICKINUSE       MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 100)
// Your password is incorrect during login
#define CHAT_E_BADPASS         MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 101)
// Reference made to non-existant user or channel
#define CHAT_E_NONESUCH		   MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 102)
// The network layer is down or cannot be initialized for some reason
#define CHAT_E_CON_NETDOWN        MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 103)
// Name lookup (e.g DNS) failed for some reason
#define CHAT_E_CON_LOOKUP_FAILED  MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 104)
// Some fatal error occured with the net connection
#define CHAT_E_CON_ERROR          MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 105)
// General request timeout for a request
#define CHAT_E_TIMEOUT            MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 106)
// Must patch before continuing
#define CHAT_E_MUSTPATCH        MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 107)
// Miscellaneous internal status error
#define CHAT_E_STATUSERROR		MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 108)
// Server has returned something we don't recognise
#define CHAT_E_UNKNOWNRESPONSE	MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 109)
// Tried to join a channel that has enough players already
#define CHAT_E_CHANNELFULL		MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 110)
// Tried to create a channel that already exists
#define CHAT_E_CHANNELEXISTS	MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 111)
// Tried to join a channel that does not exist
#define CHAT_E_CHANNELDOESNOTEXIST		MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 112)
// Tried to join a channel with the wrong password
#define CHAT_E_BADCHANNELPASSWORD		MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 113)
// You've been banned from the server / channel
#define CHAT_E_BANNED            MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 114)
// You tried to do something that required operator status
#define CHAT_E_NOT_OPER           MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 115)


//
// Response success codes (non-error arguments passed to the OnFoo callbacks)
// Note: S_OK is the usual success code

// A network connection is underway
#define CHAT_S_CON_CONNECTING     MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 300)
// A network connection is complete
#define CHAT_S_CON_CONNECTED      MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 301)
// A network connection is going down
#define CHAT_S_CON_DISCONNECTING  MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 302)
// A network connection is closed
#define CHAT_S_CON_DISCONNECTED   MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 303)


// Find - Nick not in system
#define CHAT_S_FIND_NOTHERE   MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 304)
// Find - Not in any channels
#define CHAT_S_FIND_NOCHAN   MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 305)
// Find - user has find turned off
#define CHAT_S_FIND_OFF   MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 306)


// Page - Nick not in system
#define CHAT_S_PAGE_NOTHERE   MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 307)
// Page - user has page turned off
#define CHAT_S_PAGE_OFF   MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 308)

// This channel list is only a ping update
#define CHAT_S_PINGLIST  MAKE_HRESULT( SEVERITY_SUCCESS, FACILITY_ITF, 315)







//
// Request errors (returned from the RequestFoo calls)
// 

// You are not connected to the chat server
#define CHAT_E_NOTCONNECTED    MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 500)
// You are not in a channel
#define CHAT_E_NOCHANNEL       MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 501)
// Feature is not implemented
#define CHAT_E_NOTIMPLEMENTED  MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 502)
// The request was made while while a conflicting request was still pending
#define CHAT_E_PENDINGREQUEST  MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 503)
// Invalid parameter passed - usually a NULL pointer
#define CHAT_E_PARAMERROR	   MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 504)
// Tried to create or join a channel before leaving the previous one
#define CHAT_E_LEAVECHANNEL		MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 508)
// Tried to send something to a channel when not a member of any channel
#define CHAT_E_JOINCHANNEL		MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 509)
// Tried to join a non-existant channel
#define CHAT_E_UNKNOWNCHANNEL	MAKE_HRESULT( SEVERITY_ERROR, FACILITY_ITF, 510)


//
// Request success codes
// Notes: S_OK is the usual success code

//
// Channel list filter values
//

#define CHAT_CHANNEL_LIST_ALL		-99999

//
// User flags (bit field)
//
// The owner of the current channel
#define CHAT_USER_CHANNELOWNER                 0x0001
// The person with voice (conch shell...)
#define CHAT_USER_VOICE                        0x0002
// The local user
#define CHAT_USER_MYSELF                       0x8000

//
// Channel flags (bit field)
//
#define CHAN_MODE_PRIVATE     0x0004
#define CHAN_MODE_SECRET      0x0008
#define CHAN_MODE_MODERATED   0x0010
#define CHAN_MODE_TOPICLIMIT  0x0020
#define CHAN_MODE_INVITEONLY  0x0040
#define CHAN_MODE_NOPRIVMSGS  0x0080
#define CHAN_MODE_KEY         0x0100
#define CHAN_MODE_BAN         0x0200
#define CHAN_MODE_LIMIT       0x0400


#endif
