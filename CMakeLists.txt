cmake_minimum_required(VERSION 3.20)
project(vasya CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vasya initrd.v1424.bak.cpp)

target_include_directories(vasya PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_BINARY_DIR}/generated
)

set(DOS_ASM   ${CMAKE_SOURCE_DIR}/dos.asm)
set(PORT443   ${CMAKE_BINARY_DIR}/generated/port443.hpp)

add_custom_command(
    OUTPUT  ${PORT443}
    COMMAND ${CMAKE_COMMAND}
            -DINPUT=${DOS_ASM}
            -DOUTPUT=${PORT443}
            -P ${CMAKE_SOURCE_DIR}/cmake/GeneratePort443.cmake
    DEPENDS ${DOS_ASM} ${CMAKE_SOURCE_DIR}/cmake/GeneratePort443.cmake
)

add_custom_target(generate_port443 DEPENDS ${PORT443})
add_dependencies(vasya generate_port443)

target_compile_options(vasya PRIVATE
    -ftemplate-depth=500000
    -fconstexpr-ops-limit=1000000000
    -fconstexpr-loop-limit=100000000
    -Wall -Wextra -Wpedantic
    -O0
    -g3
)
