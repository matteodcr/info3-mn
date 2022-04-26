#include "../examples/utils.h"

// Pour ce fichier, j'ai essayé une solution différente pour ne pas me répéter 4 fois

#define STUB_NAME mncblas_sgemm
#define STUB_TYPE float
#define STUB_PATYPE STUB_TYPE
#define STUB_PTYPE STUB_TYPE
#define STUB_GET_SCALAR(var, s) float var = s
#define STUB_ADD(x, y) ((x) + (y))
#define STUB_MUL(x, y) ((x) * (y))
#define STUB_CONJ(cond, x) (x)
#define STUB_ZERO ((float) 0)

#include "gemm_stub.c"

#define STUB_NAME mncblas_dgemm
#define STUB_TYPE double
#define STUB_PATYPE STUB_TYPE
#define STUB_PTYPE STUB_TYPE
#define STUB_GET_SCALAR(var, s) double var = s
#define STUB_ADD(x, y) ((x) + (y))
#define STUB_MUL(x, y) ((x) * (y))
#define STUB_CONJ(cond, x) (x)
#define STUB_ZERO ((double) 0)

#include "gemm_stub.c"

#define STUB_NAME mncblas_cgemm
#define STUB_TYPE complexe_float_t
#define STUB_PATYPE void
#define STUB_PTYPE void*
#define STUB_GET_SCALAR(var, s) STUB_TYPE var = *((STUB_TYPE*) s)
#define STUB_ADD(x, y) add_complexe_float(x, y)
#define STUB_MUL(x, y) mult_complexe_float(x, y)
#define STUB_CONJ(cond, x) cond_conj_f((cond), (x))
#define STUB_ZERO ((complexe_float_t) { .real = 0, .imaginary = 0 })

#include "gemm_stub.c"

#define STUB_NAME mncblas_zgemm
#define STUB_TYPE complexe_double_t
#define STUB_PATYPE void
#define STUB_PTYPE void*
#define STUB_GET_SCALAR(var, s) STUB_TYPE var = *((STUB_TYPE*) s)
#define STUB_ADD(x, y) add_complexe_double(x, y)
#define STUB_MUL(x, y) mult_complexe_double(x, y)
#define STUB_CONJ(cond, x) cond_conj_d((cond), (x))
#define STUB_ZERO ((complexe_double_t) { .real = 0, .imaginary = 0 })

#include "gemm_stub.c"
