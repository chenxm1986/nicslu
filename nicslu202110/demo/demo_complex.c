#include <stdio.h>
#include <stdlib.h>
#include "nicslu.h"

#ifdef _WIN32
#pragma comment(lib, "nicslu.lib")
#endif

int main()
{
    int ret;
    _complex_t ax[13] = { {1., 1.}, {-7., -7.}, {13., 13.}, {2., 2.}, {9., 9.}, {8., 8.}, {-3., -3.}, {-4., -4.},
        {11., 11.}, {5., 5.}, {10., 10.}, {12., 12.}, {6., 6.} };
    _uint_t ai[13] = { 0, 3, 4, 1, 4, 1, 2, 3, 2, 4, 0, 3, 5 };
    _uint_t ap[7] = { 0, 3, 5, 7, 8, 10, 13 };
    _complex_t b[6] = { {0., 76.}, {0., 98.}, {0., 14.}, {0., -32.}, {0., 116.}, {0., 188.} };
    INicsLU solver = NULL;
    _uint_t i;
    _double_t *cfg;
    const _double_t *stat;
    const char *err;

    PrintNicsLULicense(NULL);

    ret = NicsLU_Initialize(&solver, &cfg, &stat, &err);
    if (__FAIL(ret))
    {
        printf("Failed to initialize, return = %d\n", ret);
#ifdef _WIN32
        getchar();
#endif
        return -1;
    }
    printf("NICSLU version %.0lf\n", stat[31]);

    NicsLU_Analyze(solver, 6, (const _double_t *)ax, ai, ap, MATRIX_ROW_COMPLEX, NULL, NULL, NULL, NULL);
    NicsLU_FactorizeMatrix(solver, (const _double_t *)ax, 1);
    NicsLU_Solve(solver, (_double_t *)b, NULL);

    for (i = 0; i < 6; ++i) printf("x[%d] = (%g, %g)\n", i, b[i][0], b[i][1]);

    NicsLU_Free(solver);
#ifdef _WIN32
    getchar();
#endif
    return 0;
}
