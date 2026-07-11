cmake_minimum_required(VERSION 3.22)

project(cnc_android LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)
set(SDL_TESTS OFF CACHE BOOL "" FORCE)
set(SDL_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../third_party/SDL" "${CMAKE_BINARY_DIR}/SDL2")

include("${CMAKE_CURRENT_LIST_DIR}/../../cmake/cnc95_common.cmake")

add_library(cnc_android SHARED
    "${CNC95_REPO_ROOT}/PORT/ANDROID/src/android_main.cpp"
    ${CNC95_PLATFORM_SDL_SOURCES}
    ${CNC95_SOURCES}
    ${CNC95_SUPPORT_SOURCES}
)

cnc95_configure_target(cnc_android)

target_compile_definitions(cnc_android PRIVATE
    ANDROID
    RA_ANDROID
    RA_MOBILE_TOUCH
)

if(TARGET SDL2::SDL2)
    set(CNC95_SDL_TARGET SDL2::SDL2)
elseif(TARGET SDL2)
    set(CNC95_SDL_TARGET SDL2)
else()
    message(FATAL_ERROR "SDL2 CMake target was not created")
endif()

target_link_libraries(cnc_android PRIVATE
    ${CNC95_SDL_TARGET}
    android
    log
)

set_target_properties(cnc_android PROPERTIES
    OUTPUT_NAME main
)
