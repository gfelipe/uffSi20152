cmake_minimum_required(VERSION 3.3)
project(T3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    fila.c
    fila.h
    main.c
    pilha.c
    pilha.h)

add_executable(T3 ${SOURCE_FILES})