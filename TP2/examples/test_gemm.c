#include <stdio.h>
#include <assert.h>
#include "flop.h"

#ifndef MNBLAS_H
#define MNBLAS_H

#include "mnblas.h"

#endif

#ifndef COMPEXE_H
#define COMPEXE_H

#include "complexe.h"

#endif

#ifndef TESTUILS_H
#define TESTUILS_H

#include "utils.h"

#endif

#define NB_FOIS 4194


int main() {
    float *A = init_vec_float(12);
    float *B = init_vec_float(12);
    float *C = init_vec_float(9);

    fill_vec_float(A, 12, 1);
    fill_vec_float(B, 12, 1);

    float alphaf = 2.0;
    mncblas_sgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasNoTrans, 3, 3, 4, alphaf, A, 0, B, 0, 0, C, 0);
    assert(C[0] == 140.0 && C[7] == 576.0);

    /// Doubles

    double MatD[2] = { 1, 2 };
    double C2[1], C3[4];

    mncblas_dgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasTrans, 1, 1, 2, 1.0, MatD, 0, MatD, 0, 0, C2, 0);
    assert(C2[0] == 5.0);

    mncblas_dgemm(MNCblasRowMajor, MNCblasTrans, MNCblasNoTrans, 2, 2, 1, 1.0, MatD, 0, MatD, 0, 0, C3, 0);
    assert(C3[0] == 1.0 && C3[1] == 2.0 && C3[2] == 2.0 && C3[3] == 4.0);

    // Complexe float

    complexe_float_t MatC[2] = { { 0, 1 }, { 2, 3 } };
    complexe_float_t C4[1];

    mncblas_cgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasTrans, 1, 1, 2, &(complexe_float_t) { 1, 0 }, MatC, 0, MatC, 0, &(complexe_float_t) { 0, 0 }, C4, 0);
    assert(C4[0].real == -6.0 && C4[0].imaginary == 12.0);

    // Complexe double

    complexe_double_t MatCD[2] = { { 0, 1 }, { 2, 3 } };
    complexe_double_t C5[1];

    mncblas_cgemm(MNCblasRowMajor, MNCblasNoTrans, MNCblasConjTrans, 1, 1, 2, &(complexe_double_t) { 1, 0 }, MatCD, 0, MatCD, 0, &(complexe_double_t) { 0, 0 }, C5, 0);
    print_mat_cd(C5, 1, 1);

    printf("Les assertions sont vérifiées\n");
    return 0;
}
