cmake_minimum_required(VERSION 3.3)
project(T5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

set(SOURCE_FILES aeroporto.c fila.c fila.h)
add_executable(T5 ${SOURCE_FILES})
set_property(TARGET T5 PROPERTY C_STANDARD 99)