cmake_minimum_required(VERSION 3.3)
project(T1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    file01.in
    file02.in
    file03.in
    Trabalho01.c)

add_executable(T1 ${SOURCE_FILES})