cmake_minimum_required(VERSION 3.3)
project(T4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES
    main.c
    matriz.c
    matriz.h)

add_executable(T4 ${SOURCE_FILES})
set_property(TARGET T4 PROPERTY C_STANDARD 99)