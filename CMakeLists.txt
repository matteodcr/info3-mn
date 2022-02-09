cmake_minimum_required(VERSION 3.21)
project(info3_mn C)

set(CMAKE_C_STANDARD 11)

include_directories(TP1)

add_executable(test_poly
        TP1/test_poly.c
        TP1/poly.c
        TP1/poly.h)

add_executable(perf_poly
        TP1/perf_poly.c
        TP1/poly.c
        TP1/poly.h)
