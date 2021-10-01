#include <stdio.h>
#include <stdlib.h>
#include "nicslu.h"

#ifdef _WIN32
#pragma comment(lib, "nicslu.lib")
#endif

int main()
{
    int ret;
    _double_t ax[13] = { 1.1, -7.7, 13.13, 2.2, 9.9, 8.8, -3.3, -4.4,
        11.11, 5.5, 10.1, 12.12, 6.6 };
    _uint_t ai[13] = { 0, 3, 4, 1, 4, 1, 2, 3, 2, 4, 0, 3, 5 };
    _uint_t ap[7] = { 0, 3, 5, 7, 8, 10, 13 };
    _double_t b[6] = { 35.95, 53.9, 7.7, -17.6, 60.83, 98.18 };
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

    NicsLU_Analyze(solver, 6, ax, ai, ap, MATRIX_ROW_REAL, NULL, NULL, 
        NULL, NULL);
    NicsLU_FactorizeMatrix(solver, ax, 1);
    NicsLU_Solve(solver, b, NULL);

    for (i = 0; i < 6; ++i) printf("x[%d] = %g\n", i, b[i]);

    NicsLU_Free(solver);
#ifdef _WIN32
    getchar();
#endif
    return 0;
}
