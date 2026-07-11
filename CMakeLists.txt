cmake_minimum_required(VERSION 3.22)

project(cnc_mac LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)

include(cmake/cnc95_common.cmake)

add_executable(cnc_mac
    PORT/MAC/src/main.cpp
    ${CNC95_PLATFORM_SDL_SOURCES}
    ${CNC95_SOURCES}
    ${CNC95_SUPPORT_SOURCES}
)

cnc95_configure_target(cnc_mac)

target_link_libraries(cnc_mac PRIVATE
    PkgConfig::SDL2
)
