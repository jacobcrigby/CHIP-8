cmake_minimum_required(VERSION 3.25)
project(
    CHIP-8
    VERSION 0.1.0
    DESCRIPTION "A simple CHIP-8 emulator"
    LANGUAGES C CXX
)
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)

set(SRC
    main.c
    emu.cpp
    chip-8.cpp
)

IF (WIN32)
    add_executable(CHIP-8 WIN32 main.c emu.cpp chip-8.cpp)
ELSEIF (APPLE)
    add_executable(CHIP-8 MACOSX_BUNDLE main.c emu.cpp chip-8.cpp)
    set_target_properties(CHIP-8 PROPERTIES MACOSX_BUNDLE_GUI_IDENTIFIER "com.github.0x1f3f.chip8")
    set_target_properties(CHIP-8 PROPERTIES MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}")
    set_target_properties(CHIP-8 PROPERTIES MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}")
    set_target_properties(CHIP-8 PROPERTIES MACOSX_BUNDLE_COPYRIGHT "Copyright © 2023 0x1f3f")
ELSE()
    add_executable(CHIP-8 main.c emu.cpp chip-8.cpp)
ENDIF()

target_link_libraries(CHIP-8 PRIVATE SDL3::SDL3)
