/*
 *
 * Copyright (C) 2019, Broadband Forum
 * Copyright (C) 2016-2019  CommScope, Inc
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * \file vendor_defs.h
 *
 * Header file containing defines controlling the build of USP Agent,
 * which may be modified by the vendor
 *
 */
#ifndef VENDOR_DEFS_H
#define VENDOR_DEFS_H

//Device.LocalAgent.Controller.1.EndpointID
//Device.STOMP.Connection.1.Host
//Device.STOMP.Connection.1.Username
//Device.STOMP.Connection.1.Password
//Device.STOMP.Connection.1.X_ARRIS-COM_EnableEncryption
//Device.LocalAgent.MTP.1.STOMP.Destination
//Device.LocalAgent.EndpointID

#define LocalAgent_Controller_EndpointID "os::012345-0242AC110007"
#define STOMP_Connection_Host     "usp.krms.kaonmedia.com"
#define STOMP_Connection_Username "user"
#define STOMP_Connection_Password "user"
#define STOMP_Connection_X_ARRIS_M_EnableEncryption "false"
#define LocalAgent_MTP_STOMP_Destination "/topic/msg/012345-0242AC110120"
#define LocalAgent_EndpointID "012345-0242AC110120"



//------------------------------------------------------------------------------
// Definitions used to size static arrays
// You are unlikely to need to change these
#define MAX_DM_INSTANCES 128      // Maximum number of instances of a single object
#define MAX_DM_INSTANCE_ORDER 6   // Maximum number of instance numbers in a data model schema path (ie number of '{i}' in the schema path)
#define MAX_DM_PATH (256)           // Maximum number of characters in a data model path
#define MAX_DM_VALUE_LEN (4096)     // Maximum number of characters in a data model parameter value
#define MAX_DM_SHORT_VALUE_LEN (MAX_DM_PATH) // Maximum number of characters in an (expected to be) short data model parameter value
#define MAX_PATH_SEGMENTS (32)      // Maximum number of segments (eg "Device, "LocalAgent") in a path. Does not include instance numbers.
#define MAX_COMPOUND_KEY_PARAMS 4   // Maximum number of parameters in a compound unique key
#define MAX_CONTROLLERS 5           // Maximum number of controllers which may be present in the DB (Device.LocalAgent.Controller.{i})
#define MAX_CONTROLLER_MTPS 3       // Maximum number of MTPs that a controller may have in the DB (Device.LocalAgent.Controller.{i}.MTP.{i})
#define MAX_AGENT_MTPS (MAX_CONTROLLERS)  // Maximum number of MTPs that an agent may have in the DB (Device.LocalAgent.MTP.{i})
#define MAX_STOMP_CONNECTIONS (MAX_CONTROLLERS)  // Maximum number of STOMP connections that an agent may have in the DB (Device.STOMP.Connection.{i})
#define MAX_COAP_CONNECTIONS (MAX_CONTROLLERS)  // Maximum number of CoAP connections that an agent may have in the DB (Device.LocalAgent.Controller.{i}.MTP.{i}.CoAP)
#define MAX_COAP_SERVERS 5          // Maximum number of interfaces which an agent listens for CoAP messages on
#define MAX_COAP_CLIENTS (MAX_CONTROLLERS)  // Maximum number of CoAP controllers which an agent sends to
#define MAX_COAP_SERVER_SESSIONS 2      // Maxiumum number of simultaneous sessions with CoAP controllers which the agent can service
#define MAX_FIRMWARE_IMAGES 2       // Maximum number of firmware images that the CPE can hold in flash at any one time
#define MAX_ACTIVATE_TIME_WINDOWS 5 // Maximum number of time windows allowed in the Activate() command's input arguments

// Maximum number of bytes allowed in a USP protobuf message. 
// This is not used to size any arrays, just used as a security measure to prevent rogue controllers crashing 
// the agent process with out of memory
#define MAX_USP_MSG_LEN (64*1024)

// Period of time (in seconds) between polling values that have value change notification enabled on them
#define VALUE_CHANGE_POLL_PERIOD  (30)

// Location of the database file to use, if none is specified on the command line when invoking this executable
// NOTE: As the database needs to be stored persistently, this should be changed to a directory which is not cleared on boot up

//llewnoiz
#if !defined(ANDROID_FEATURE)
#define DEFAULT_DATABASE_FILE               "/tmp/usp.db"
#else
//#define DEFAULT_DATABASE_FILE               "/data/vendor/nxmedia/RMS/usp.db"
#define DEFAULT_DATABASE_FILE               "/data/data/com.kaon.song/usp.db"
//#define DEFAULT_DATABASE_FILE               "/cache/usp.db"
#endif

// Location of unix domain stream file used for CLI communication between client and server
//llewnoiz
#if !defined(ANDROID_FEATURE)
#define CLI_UNIX_DOMAIN_FILE                "/tmp/usp_cli"
#else
//#define CLI_UNIX_DOMAIN_FILE                "/data/vendor/nxmedia/RMS/usp_cli"
#define CLI_UNIX_DOMAIN_FILE                "/data/data/com.kaon.song/usp_cli"
//#define CLI_UNIX_DOMAIN_FILE                "/cache/usp_cli"
#endif
//-----------------------------------------------------------------------------------------
// Defines associated with factory reset database
// Location of the file containing a factory reset database (SQLite database file)
// NOTE: This may be NULL or an empty string, if the factory reset database is created by an external script, rather than being a simple fixed file.
#define FACTORY_RESET_FILE      ""

// Uncomment the following to get the values of the factory reset parameters from VENDOR_GetFactoryResetParams()
#define INCLUDE_PROGRAMMATIC_FACTORY_RESET

//-----------------------------------------------------------------------------------------
// Uncomment the following to remove code and features from the standard build
//#define REMOVE_DEVICE_INFO               // Removes DeviceInfo from the core data model. It must instead be provided by the vendor.
//#define REMOVE_SELF_TEST_DIAG_EXAMPLE    // Removes Self Test diagnostics example code

//#define DONT_SORT_GET_INSTANCES          // Disables the sorting of data model paths returned in a GetInstancesResponse. Useful for slow devices supporting large data models.

// Uncomment the following defines to add code and features to the standard build
//#define VALIDATE_OUTPUT_ARG_NAMES        // Checks that the output argument names in operations and events formed by code in USP Agent 
                                           // match the schema registered in the data model by USP_REGISTER_OperationArguments() and USP_REGISTER_EventArguments
//-----------------------------------------------------------------------------------------
// The following define controls whether STOMP connects over the default WAN interface, or
// whether the Linux routing tables can decide which interface to use
// Comment out the following define if you want to let the Linux routing tables decide which network interface to use for USP connections
// Letting the Linux routing tables decide is better for devices that can connect to the STOMP server through either
// WiFi or ethernet, and either of these interfaces could be down at any one time
#define CONNECT_ONLY_OVER_WAN_INTERFACE

//-----------------------------------------------------------------------------------------
// OUI (Organization Unique Identifier) to use for this CPE. This code will be unique to the manufacturer
// This may be overridden by an environment variable. See GetDefaultOUI(). Or by a vendor hook for Device.DeviceInfo.ManufacturerOUI (if REMOVE_DEVICE_INFO is defined)
#define VENDOR_OUI "012345"

// Various defines for constant parameters in Device.DeviceInfo
// These defines are only used if USP Agent core implements DeviceInfo (see REMOVE_DEVICE_INFO above)
// These defines MUST be modified by the vendor
#define VENDOR_PRODUCT_CLASS "USP Agent"   // Configures the value of Device.DeviceInfo.ProductClass
#define VENDOR_MANUFACTURER  "Manufacturer"   // Configures the value of Device.DeviceInfo.Manufacturer
#define VENDOR_MODEL_NAME    "USP Agent"   // Configures the value of Device.DeviceInfo.ModelName

// URI of data model implemented by USP Agent
#define BBF_DATA_MODEL_URI "urn:broadband-forum-org:tr-181-2-12-0"

// Name of interface on which the WAN is connected.
// This interface is used to get the serial number of the agent (as MAC address) for the endpoint_id string
// It is also the interface used for all USP communications
// This may be overridden using the '-i' option or by an environment variable. See nu_macaddr_wan_ifname().
#define DEFAULT_WAN_IFNAME "eth0"

// Key used to obfuscate (using XOR) all secure data model parameters stored in the USP Agent database (eg passwords)
#define PASSWORD_OBFUSCATION_KEY  "$%^&*()@~#/,?"

// Timeout (in seconds) when performing a connect to a STOMP broker
#define STOMP_CONNECT_TIMEOUT 30

// Number of seconds after a STOMP server heartbeat was expected, before retrying the connection
#define STOMP_SERVER_HEARTBEAT_GRACE_PERIOD 10

// Delay before starting USP Agent as a daemon. Used as a workaround in cases where other services (eg DNS) are not ready at the time USP Agent is started
#define DAEMON_START_DELAY_MS   0

// Comma separated list of network interface names on which CoAP should listen for USP messages
// An empty list or "any" indicates to listen on all interfaces
// This may be overridden using the '-i' option (only one interface name is supported, if using '-i')
#define COAP_LISTEN_INTERFACES    "eth0"  /* "lo, enp0s9" */

//-----------------------------------------------------------------------------------------
// Defines for Bulk Data Collection
// NOTE: Some of these integer values are converted to string literals by C-preprocessor for registering parameter defaults
//       So these values must be simple ints, and must not contain brackets etc
//       If after modifying, you are unsure, try reading back the default values from an empty database and checking that they make sense
#define BULKDATA_MAX_PROFILES 5                    // Maximum number of bulk data profiles supported
#define BULKDATA_MAX_RETAINED_FAILED_REPORTS 3     // Maximum number of retained failed bulk data reports
#define BULKDATA_MINIMUM_REPORTING_INTERVAL 300    // Minimum supported reporting interval, in seconds
#define BULKDATA_HTTP_AUTH_METHOD  CURLAUTH_BASIC  // HTTP Authentication method to use. Note: Normally over https

#define BULKDATA_CONNECT_TIMEOUT 30   // Timeout (in seconds) when attempting to connect to a bulk data collection server
#define BULKDATA_TOTAL_TIMEOUT   60   // Total timeout (in seconds) to connect and send to a bulk data collection server
                                      // BULKDATA_TOTAL_TIMEOUT includes BULKDATA_CONNECT_TIMEOUT, so should be larger than it.

//-----------------------------------------------------------------------------------------
// Static Declaration of all Controller Trust roles
// The names of all enumerations may be altered, and enumerations added/deleted, but the last entry must always be kCTrustRole_Max
typedef enum
{
    kCTrustRole_Min = 0,
    kCTrustRole_FullAccess = 0,
    kCTrustRole_Untrusted,

    kCTrustRole_Max         // This must always be the last entry in this enumeration. It is used to statically size arrays
} ctrust_role_t;

// Definitions of roles used
#define ROLE_NON_SSL       kCTrustRole_FullAccess  // Role to use, if SSL is not being used
#define ROLE_DEFAULT       kCTrustRole_FullAccess  // Default Role to use for controllers until determined from MTP certificate





#endif
