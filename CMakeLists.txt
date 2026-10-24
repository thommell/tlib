cmake_minimum_required(VERSION 3.16)

project(tlib LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(tlib STATIC
    src/logger/tlogger.c
    src/string/tstring.c
    src/linked-list/tlinked-list.c
    src/array/tarray.c
)

target_include_directories(tlib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(tlib PUBLIC c_std_11)

add_executable(tlib_example
    tests/main.c
)

target_link_libraries(tlib_example PRIVATE tlib)

option(TLIB_SANITIZE "Enable AddressSanitizer" OFF)

if(TLIB_SANITIZE AND CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(tlib PRIVATE
        -fsanitize=address
        -fno-omit-frame-pointer
        -g
    )

    target_link_options(tlib INTERFACE
        -fsanitize=address
    )
endif()
