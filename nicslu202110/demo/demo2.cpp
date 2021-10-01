//this demo is the same as demo.c except for that this demo calls the native C++ interface

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "nicslu.h"

#ifdef _WIN32
#pragma comment(lib, "nicslu.lib")
#endif

const char *const ORDERING_METHODS[] = { "", "", "", "", "AMD", "AMM", "AMO1","AMO2","AMO3","AMDF" };

int main()
{
    int ret;
    _double_t *ax = NULL, *b = NULL, *x = NULL;
    _uint_t *ai = NULL, *ap = NULL;
    _uint_t n, row, col, nz, nnz, i, j;
    INicsLU solver = NULL;
    _double_t res[4], cond, det1, det2, fflop, sflop;
    size_t mem;
    _double_t *cfg;
    const _double_t *stat;

    /*print license*/
    PrintNicsLULicense(NULL);

    /*read matrix A*/
    if (__FAIL(ReadMatrixMarketFile("add20.mtx", &row, &col, &nz, NULL, NULL, NULL, NULL, NULL, NULL)))
    {
        printf("Failed to read matrix A\n");
        goto EXIT;
    }
    n = row;
    nnz = nz;
    ax = (_double_t *)malloc(sizeof(_double_t)*nnz);
    ai = (_uint_t *)malloc(sizeof(_uint_t)*nnz);
    ap = (_uint_t *)malloc(sizeof(_uint_t)*(1 + n));
    ReadMatrixMarketFile("add20.mtx", &row, &col, &nz, ax, ai, ap, NULL, NULL, NULL);
    printf("Matrix A: row %d, col %d, nnz %d\n", n, n, nnz);

    /*read RHS B*/
    b = (_double_t *)malloc(sizeof(_double_t)*n);
    ReadMatrixMarketFile("add20_b.mtx", &row, &col, &nz, b, NULL, NULL, NULL, NULL, NULL);

    x = (_double_t *)malloc(sizeof(_double_t)*n);
    memset(x, 0, sizeof(_double_t) * n);

    /*initialize solver*/
    ret = NicsLU_Initialize(&solver, &cfg, &stat, NULL);
    if (__FAIL(ret))
    {
        printf("Failed to initialize, return = %d\n", ret);
        goto EXIT;
    }
    printf("NICSLU version %.0lf\n", stat[31]);
    cfg[0] = 1.; /*enable timer*/

    /*pre-ordering (do only once)*/
    solver->Analyze(n, ax, ai, ap, MATRIX_ROW_REAL, NULL, NULL, NULL, NULL);
    printf("analysis time: %g\n", stat[0]);
    printf("best ordering method: %s\n", ORDERING_METHODS[(int)stat[16]]);

    /*create threads (do only once)*/
    solver->CreateThreads(0); /*use all physical cores*/

    /*factor & solve (first-time)*/
    solver->FactorizeMatrix(ax, 0); /*use all created threads*/
    printf("factor time: %g\n", stat[1]);
    solver->Solve(b, x);
    printf("solve time: %g\n", stat[2]);

    SparseResidual(n, ax, ai, ap, b, x, res, MATRIX_ROW_REAL);
    printf("residual RMSE: %g\n", res[0]);

    /*Now we have finished a factorization and a solving.
    In many applications like circuit simulation, 
    we need to solve the linear system many times with different values (but the symbolic pattern keeps unchanged).
    The following code simulates such a case.*/

    for (j = 0; j < 5; ++j) /*do 5 iterations*/
    {
        /*matrix and RHS values change*/
        for (i = 0; i < nnz; ++i) ax[i] *= (_double_t)rand() / RAND_MAX * 2.;
        for (i = 0; i < n; ++i) b[i] *= (_double_t)rand() / RAND_MAX * 2.;

        /*factor & solve again based on the changed matrix & RHS*/
        solver->FactorizeMatrix(ax, 0); /*use all created threads*/
        printf("factor [%d] time: %g\n", j + 1, stat[1]);
        solver->Solve(b, x);
        printf("solve [%d] time: %g\n", j + 1, stat[2]);

        SparseResidual(n, ax, ai, ap, b, x, res, MATRIX_ROW_REAL);
        printf("residual [%d] RMSE: %g\n", j + 1, res[0]);
    }

    /*finally, print some statistical information*/
    printf("nnz(factors): %.0lf\n", stat[8]); //# of factors

    solver->Flops(1, &fflop, &sflop);
    printf("factor flops: %e, solving flops: %e\n", fflop, sflop); /*# of flops*/

    solver->ConditionNumber(ax, &cond); /*condition number estimation*/
    printf("condest: %g\n", cond);

    solver->Determinant(&det1, &det2); /*determinant*/
    printf("determinant: %.16lf x 10^(%.0lf)\n", det1, det2);

    solver->MemoryUsage(&mem); /*get virtual memory usage*/
    printf("memory usage: %.0lf KB\n", (double)(mem >> 10));

    solver->DrawFactors("add20.bmp", 512);

EXIT:
    free(ax);
    free(ai);
    free(ap);
    free(b);
    free(x);
    solver->Free();
#ifdef _WIN32
    getchar();
#endif
    return 0;
}
