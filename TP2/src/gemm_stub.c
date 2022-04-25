#ifndef STUB_NAME
#error "STUB_NAME n'est pas défini"
#endif

#ifndef STUB_TYPE
#error "STUB_TYPE n'est pas défini"
#endif

void STUB_NAME(MNCBLAS_LAYOUT layout, MNCBLAS_TRANSPOSE TransA,
    MNCBLAS_TRANSPOSE TransB, const int M, const int N,
    const int K, const STUB_PTYPE alpha_, const STUB_PATYPE *A,
    const int lda, const STUB_PATYPE *B, const int ldb,
    const STUB_PTYPE beta_, STUB_PATYPE *C, const int ldc) {

    STUB_GET_SCALAR(alpha, alpha_);
    STUB_GET_SCALAR(beta, beta_);

    bool trans = (layout == MNCblasColMajor);
    bool trans_a = trans ^ (TransA > MNCblasNoTrans);
    bool trans_b = trans ^ (TransB > MNCblasNoTrans);
    bool conj_a = TransA == MNCblasConjTrans;
    bool conj_b = TransB == MNCblasConjTrans;

    for (size_t y = 0; y < M; y++) {
        for (size_t x = 0; x < N; x++) {
            STUB_TYPE* cell = MAT_Y_X(STUB_TYPE, C, M, N, y, x, trans);

            STUB_TYPE sum = STUB_ZERO;
            for (size_t k = 0; k < K; k++) {
                STUB_TYPE a = STUB_CONJ(conj_a, *MAT_Y_X(STUB_TYPE, A, M, K, y, k, trans_a));
                STUB_TYPE b = STUB_CONJ(conj_b, *MAT_Y_X(STUB_TYPE, B, K, N, k, x, trans_b));
                sum = STUB_ADD(sum, STUB_MUL(a, b));
            }

            *cell = STUB_ADD(STUB_MUL(alpha, sum), STUB_MUL(beta, *cell));
        }
    }
}

#undef STUB_NAME
#undef STUB_TYPE
#undef STUB_PATYPE
#undef STUB_PTYPE
#undef STUB_GET_SCALAR
#undef STUB_ADD
#undef STUB_MUL
#undef STUB_CONJ
#undef STUB_ZERO
