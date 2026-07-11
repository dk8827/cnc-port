cmake_minimum_required(VERSION 3.22)

project(cnc_ios LANGUAGES C CXX OBJC)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "iOS")
    message(FATAL_ERROR "Configure the iOS target with -DCMAKE_SYSTEM_NAME=iOS, or use scripts/build_ios_debug.sh.")
endif()

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(NOT DEFINED CMAKE_OSX_DEPLOYMENT_TARGET)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "13.0" CACHE STRING "" FORCE)
endif()

set(SDL_SHARED OFF CACHE BOOL "" FORCE)
set(SDL_STATIC ON CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)
set(SDL2_DISABLE_INSTALL ON CACHE BOOL "" FORCE)

set(CNC95_IOS_BUNDLED_ASSETS_DIR "${CMAKE_CURRENT_LIST_DIR}/../assets/cnc" CACHE PATH "Local Command & Conquer assets to bundle into the iOS debug app.")

if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/third_party/SDL/CMakeLists.txt")
    message(FATAL_ERROR "Missing SDL2 sources at ios/third_party/SDL. Run scripts/build_ios_debug.sh to fetch them.")
endif()

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/third_party/SDL" "${CMAKE_BINARY_DIR}/SDL2")

include("${CMAKE_CURRENT_LIST_DIR}/../cmake/cnc95_common.cmake")

add_executable(cnc_ios MACOSX_BUNDLE
    "${CNC95_REPO_ROOT}/PORT/IOS/src/ios_app_delegate.m"
    "${CNC95_REPO_ROOT}/PORT/IOS/src/ios_main.cpp"
    ${CNC95_PLATFORM_SDL_SOURCES}
    ${CNC95_SOURCES}
    ${CNC95_SUPPORT_SOURCES}
)

cnc95_configure_target(cnc_ios)

target_compile_definitions(cnc_ios PRIVATE
    RA_IOS
    RA_MOBILE_TOUCH
)

target_include_directories(cnc_ios PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/third_party/SDL/src/video/uikit"
)

if(TARGET SDL2::SDL2main)
    set(CNC95_SDLMAIN_TARGET SDL2::SDL2main)
elseif(TARGET SDL2main)
    set(CNC95_SDLMAIN_TARGET SDL2main)
else()
    message(FATAL_ERROR "SDL2main CMake target was not created")
endif()

if(TARGET SDL2::SDL2-static)
    set(CNC95_SDL_TARGET SDL2::SDL2-static)
elseif(TARGET SDL2-static)
    set(CNC95_SDL_TARGET SDL2-static)
elseif(TARGET SDL2::SDL2)
    set(CNC95_SDL_TARGET SDL2::SDL2)
elseif(TARGET SDL2)
    set(CNC95_SDL_TARGET SDL2)
else()
    message(FATAL_ERROR "SDL2 CMake target was not created")
endif()

target_link_libraries(cnc_ios PRIVATE
    ${CNC95_SDLMAIN_TARGET}
    ${CNC95_SDL_TARGET}
)

set_target_properties(cnc_ios PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/Info.plist.in"
    XCODE_ATTRIBUTE_CODE_SIGN_STYLE "Automatic"
    XCODE_ATTRIBUTE_PRODUCT_BUNDLE_IDENTIFIER "com.cncport.cnc"
    XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2"
)

add_custom_command(TARGET cnc_ios POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E make_directory "$<TARGET_BUNDLE_DIR:cnc_ios>/assets"
    COMMAND "${CMAKE_COMMAND}" -E copy_directory "${CNC95_IOS_BUNDLED_ASSETS_DIR}" "$<TARGET_BUNDLE_DIR:cnc_ios>/assets/cnc"
    COMMENT "Copying local Command & Conquer assets into the iOS debug bundle"
)
