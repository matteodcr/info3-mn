cmake_minimum_required(VERSION 3.21)
project(TP2 C)

set(CMAKE_C_STANDARD 11)

include_directories(examples)
include_directories(include)


add_executable(test_copy
        examples/test_copy.c
        examples/utils.c
        src/complexe.c
        src/copy.c
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )
