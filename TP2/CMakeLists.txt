cmake_minimum_required(VERSION 3.21)
project(TP2 C)

set(CMAKE_C_STANDARD 11)

include_directories(examples)
include_directories(include)

add_executable(test_complexe
        examples/test_complexe.c
        examples/utils.c
        src/complexe.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_complexe2
        examples/test_complexe2.c
        examples/utils.c
        examples/flop.c
        examples/flop.h
        src/complexe.c
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_complexe3
        examples/test_complexe3.c
        examples/utils.c
        src/complexe.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_swap
        examples/test_swap.c
        examples/utils.c
        src/complexe.c
        src/swap.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_copy
        examples/test_copy.c
        examples/utils.c
        src/complexe.c
        src/copy.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_dot
        examples/test_dot.c
        examples/utils.c
        src/complexe.c
        src/dot.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_axpy
        examples/test_axpy.c
        examples/utils.c
        src/complexe.c
        src/axpy.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_asum
        examples/test_asum.c
        examples/utils.c
        src/complexe.c
        src/asum.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_iamin
        examples/test_iamin.c
        examples/utils.c
        src/complexe.c
        src/iamin.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_iamax
        examples/test_iamax.c
        examples/utils.c
        src/complexe.c
        src/iamax.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_nrm2
        examples/test_nrm2.c
        examples/utils.c
        src/complexe.c
        src/nrm2.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

target_link_libraries(test_nrm2 m)

add_executable(test_gemv
        examples/test_gemv.c
        examples/utils.c
        src/complexe.c
        src/gemv.c
        examples/flop.c
        examples/flop.h
        include/complexe.h
        include/mnblas.h
        examples/utils.h
        )

add_executable(test_gemm
        examples/test_gemm.c
        examples/utils.c
        src/complexe.c
        src/gemm.c
        examples/flop.c
        )
