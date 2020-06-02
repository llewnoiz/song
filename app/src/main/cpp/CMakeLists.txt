# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
add_definitions(-DENABLE_COAP -DHAVE_STRERROR_R -DSTRERROR_R_CHAR_P=0 -DANDROID_FEATURE -DHAVE_LRAND48)

include_directories(src)
include_directories(src/core)
include_directories(src/protobuf-c)
include_directories(src/vendor)
include_directories(src/libjson/ccan/json)
include_directories(src/libsqlite3)
include_directories(src/include)

set(openssl_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../openssl)
include_directories("${openssl_DIR}/${ANDROID_ABI}/include")

set(curl_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../curl)
include_directories("${curl_DIR}/${ANDROID_ABI}/include")

set(zip_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../zip)
include_directories("${zip_DIR}/${ANDROID_ABI}/include")

set(
        SQLITE
        src/libsqlite3/sqlite3.c
)
set(
        LIB_JSON
        src/libjson/ccan/json/json.c
)
set(
        PROTO_BUF
        src/protobuf-c/usp-msg.pb-c.c
        src/protobuf-c/usp-record.pb-c.c
        src/protobuf-c/protobuf-c.c
)
set(
        CORE
        src/core/mtp_exec.c
        src/core/dm_exec.c
        src/core/bdc_exec.c
        src/core/stomp.c
        src/core/socket_set.c
        src/core/msg_handler.c
        src/core/handle_get.c
        src/core/handle_set.c
        src/core/handle_add.c
        src/core/handle_delete.c
        src/core/handle_notify.c
        src/core/handle_operate.c
        src/core/handle_get_supported_protocol.c
        src/core/handle_get_instances.c
        src/core/handle_get_supported_dm.c
        src/core/proto_trace.c
        src/core/data_model.c
        src/core/error_resp.c
        src/core/usp_register.c
        src/core/usp_api.c
        src/core/dm_access.c
        src/core/device_local_agent.c
        src/core/device_controller.c
        src/core/device_mtp.c
        src/core/device_stomp.c
        src/core/device_subscription.c
        src/core/device_security.c
        src/core/device_firmware.c
        src/core/device_ctrust.c
        src/core/device_bulkdata.c
        src/core/device_selftest_example.c
        src/core/device_time.c
        src/core/uptime.c
        src/core/rfc1123.c
        src/core/database.c
        src/core/usp_err.c
        src/core/usp_log.c
        src/core/usp_mem.c
        src/core/nu_ipaddr.c
        src/core/nu_macaddr.c
        src/core/retry_wait.c
        src/core/path_resolver.c
        src/core/str_vector.c
        src/core/int_vector.c
        src/core/kv_vector.c
        src/core/dm_inst_vector.c
        src/core/expr_vector.c
        src/core/dm_trans.c
        src/core/subs_vector.c
        src/core/subs_retry.c
        src/core/sync_timer.c
        src/core/cli_server.c
        src/core/cli_client.c
        src/core/iso8601.c
        src/core/text_utils.c
        src/core/os_utils.c
        src/core/device_request.c
        src/core/dllist.c
        src/core/coap_common.c
        src/core/coap_client.c
        src/core/coap_server.c
        src/core/uri.c
        src/core/usp_cli.c
)
set(
        VENDOR
        src/vendor/vendor.c
        src/vendor/vendor_factory_reset_example.c
)
add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ${SQLITE}
        ${LIB_JSON}
        ${PROTO_BUF}
        ${CORE}
        ${VENDOR}
        native-lib.c
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)


add_library( libssl STATIC IMPORTED )
set_target_properties( libssl
        PROPERTIES
        IMPORTED_LOCATION
        ${openssl_DIR}/${ANDROID_ABI}/lib/libssl.a)

add_library( libcrypto STATIC IMPORTED )
set_target_properties( libcrypto
        PROPERTIES
        IMPORTED_LOCATION
        ${openssl_DIR}/${ANDROID_ABI}/lib/libcrypto.a)

add_library( libcurl STATIC IMPORTED )
set_target_properties( libcurl
        PROPERTIES
        IMPORTED_LOCATION
        ${curl_DIR}/${ANDROID_ABI}/lib/libcurl.a)

add_library( libz STATIC IMPORTED )
set_target_properties( libz
        PROPERTIES
        IMPORTED_LOCATION
        ${zip_DIR}/${ANDROID_ABI}/lib/libz.a)

target_include_directories(native-lib PRIVATE
        ${openssl_DIR}/include )

target_include_directories(native-lib PRIVATE
        ${curl_DIR}/include )

target_include_directories(native-lib PRIVATE
        ${zip_DIR}/include )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        native-lib
        libssl
        libcrypto
        libcurl
        libz
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})