/*
Interface of NICSLU
Version: 201901
Copyright by NICS laboratory, Tsinghua University

NICSLU is a parallel sparse solver designed for MNA-based SPICE simulation problems.
*/

#ifndef __NICSLU__
#define __NICSLU__

#include "nics_common.h"

/*-------------------------------------------------------------------------------------------------*/
/*Specification of statistical information (_double_t stat[32])                                    */
/*-------------------------------------------------------------------------------------------------*/
/*
stat[0]: runtime of NicsLU_Analyze
stat[1]: runtime of NicsLU_Factorize, NicsLU_ReFactorize, or NicsLU_FactorizeMatrix
stat[2]: runtime of NicsLU_Solve or NicsLU_SolveMatrix
stat[3]: predicted # of flops
stat[4]: predicted NNZ(L+U-I)
stat[5]: structural symmetry
stat[6]: runtime of NicsLU_Refine
stat[7]: # of iterations performed by NicsLU_Refine
stat[8]: NNZ(L+U-I)
stat[9]: NNZ(L)
stat[10]: NNZ(U)
stat[11]: # of off-diagonal pivots
stat[12]: # of supernodes
stat[13]: # of perturbed pivots
stat[14]: # of factorizations performed
stat[15]: # of refactorizations performed
stat[29]: license expiration date (YYYYMMDD)
stat[30]: build time (YYYYMMDD.HHMMSS)
stat[31]: version of NICSLU (YYYYMM)
*/

/*-------------------------------------------------------------------------------------------------*/
/*Specification of configuration (_double_t cfg[32])                                               */
/*-------------------------------------------------------------------------------------------------*/
/*
cfg[0]: enable built-in timer. [default] 0: no timer; >0: high-precision; <0: low-precision
cfg[1]: threshold for partial pivoting. [default] 0.001
cfg[2]: synchronization method. [default] <=0: block waiting; >0: spin waiting
cfg[3]: ordering method. 0: no ordering; 1: user-provided ordering; 2 or -2: AMD; 3 or -3: modified AMD;
        4 or -4: COLAMD; 5 or -5: METIS; 6 or -6: AMF; 7 or -7: modified AMF. 8 or -8: best one in AMD, 
        mAMD, AMF and mAMF. Negative: output order. [default] 8
cfg[4]: threshold for dense rows for AMD or COLAMD. [default] 10.0
cfg[5]: pre-ordering method. [default] 0: static pivoting; >0: static pivoting+scaling; <0: zero-free permutation
cfg[6]: for pre-allocating memory. [default] 4
cfg[7]: memory growth factor. [default] 1.5
cfg[8]: # of columns for supernodes. [default] 80
cfg[9]: # of init rows for supernodes. [default] 4
cfg[10]: for pipeline scheduling. [default] 8
cfg[11]: for load balance. [default] 0.95
cfg[12]: dynamic scaling. [default] 0: no scaling; >0: max-scaling; <0: sum-scaling
cfg[13]: automatically control serial/parallel factorization. [default] 1
cfg[14]: max # of iterations for refinement. [default] 3
cfg[15]: residual requirement for refinement. [default] 1e-10
cfg[16]: pseudo condition number threshold for doing refinement. [default] 1e+12
cfg[17]: threshold for calling factorization or refactorization. [default] 5
cfg[18]: threshold for pivot perturbation. [default] 0
cfg[19]: threshold for garbage collection. [default] 2
*/

/*-------------------------------------------------------------------------------------------------*/
/*Specification of return code                                                                     */
/*-------------------------------------------------------------------------------------------------*/
/*
0: successful
-100: no license found
-101: license invalid
-102: license expired
-103: license restricted
-104: other license error
-1: invalid context
-2: argument error
-3: out of memory
-4: structurally singular
-5: numerically singular
-6: input data error
-7: duplicated entries
-8: threads not created
-9: create threads failed
-10: matrix not analyzed
-11: matrix not factorized
-12: abnormal numerical values
-13: int32 overflow
-14: file cannot open
-255: unknown error
+1: set thread schedule failed
+2: static scaling invalid
+3: threads already created
*/

typedef enum
{
	MATRIX_ROW_REAL = 0,
	MATRIX_COLUMN_REAL,
	MATRIX_ROW_COMPLEX,
	MATRIX_COLUMN_COMPLEX
} _matrix_type_t;

typedef enum
{
	THREAD_BINDING = 0,
	THREAD_PRIORITY
} _thread_sched_t;

typedef enum
{
	TRANSPOSE_REAL = 0,
	TRANSPOSE_COMPLEX,
	TRANSPOSE_COMPLEX_CONJ
} _transpose_t;

#ifdef __cplusplus
extern "C" {
#endif

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Initialize: creates solver context and initializes internal data                          */
/*-------------------------------------------------------------------------------------------------*/
/*Initializes configurations and checks license.*/
int NicsLU_Initialize
(
	__OUT _handle_t *ctx,			/*returns context pointer*/
	__OUT _double_t **cfg,			/*returns configuration array pointer (can be NULL)*/
	__OUT const _double_t **stat,	/*returns statistics array pointer (can be NULL)*/
	__OUT const char **last_err		/*returns last error pointer (can be NULL)*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Free: frees all internal data and destroys solver context                                 */
/*-------------------------------------------------------------------------------------------------*/
/*Must call this routine at last, otherwise memory leaks.*/
int NicsLU_Free
(
	__IN _handle_t ctx
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Analyze: orders, pivots and scales the matrix                                             */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_Analyze
(
	__IN _handle_t ctx,
	__IN _uint_t n,					/*matrix dimension*/
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__IN const _uint_t *ai,			/*length ap[n], column indexes*/
	__IN const _uint_t *ap,			/*length n+1, row pointers*/
	__IN _matrix_type_t mtype,		/*matrix type*/
	__INOROUT _uint_t *row_perm,	/*length n, user permutation or output (can be NULL)*/
	__INOROUT _uint_t *col_perm,	/*length n, user permutation or output (can be NULL)*/
	__OUT _double_t *row_scale,		/*length n, outputs row scaling vector (can be NULL)*/
	__OUT _double_t *col_scale		/*length n, outputs column scaling vector (can be NULL)*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_CreateThreads: creates threads                                                            */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_CreateThreads
(
	__IN _handle_t ctx,
	__IN int threads				/*# of threads. Set 0 to use all physical cores. 
									Cannot exceed # of logical cores.*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_SetThreadSchedule: sets threads' scheduling-related parameters                            */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_SetThreadSchedule
(
	__IN _handle_t ctx,
	__IN _thread_sched_t op,		/*operation code*/
	__IN int param					/*for op=THREAD_BINDING: >=0: binds threads to cores from 'param'; <0: unbinds.
									For op=THREAD_PRIORITY: 0~99 indicating thread priority. 0 is normal priority.*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_DestroyThreads: destroys threads                                                          */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_DestroyThreads
(
	__IN _handle_t ctx
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Factorize: factorizes the matrix with partial pivoting                                    */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_Factorize
(
	__IN _handle_t ctx,
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__IN int threads				/*# of threads. Set 0 to use all created threads*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_ReFactorize: refactorizes the matrix without partial pivoting                             */
/*-------------------------------------------------------------------------------------------------*/
/*Uses same pivoting order as NicsLU_Factorize*/
int NicsLU_ReFactorize
(
	__IN _handle_t ctx,
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__IN int threads				/*# of threads. Set 0 to use all created threads*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Solve: forward/backward substitutions                                                     */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_Solve
(
	__IN _handle_t ctx,
	__INANDOUT _double_t *b,		/*length n (_double_t or _complex_t), RHS (and solution if x is NULL)*/
	__OUT _double_t *x				/*length n (_double_t or _complex_t), solution (can be NULL, overwrite b)*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Refine: refines solution                                                                  */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_Refine
(
	__IN _handle_t ctx,
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__IN const _double_t *b,		/*length n (_double_t or _complex_t), RHS*/
	__INANDOUT _double_t *x			/*length n (_double_t or _complex_t), solution*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Flops: calculates # of flops for factorization and solving                                */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_Flops
(
	__IN _handle_t ctx,
	__IN int threads,				/*# of threads*/
	__OUT _double_t *fflops,		/*returns # of flops of each thread in factorization*/
	__OUT _double_t *sflops			/*returns # of flops in solving*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_MemoryTraffic: calculates memory traffic for factorization and solving                    */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_MemoryTraffic
(
	__IN _handle_t ctx,
	__OUT _double_t *fcomm,			/*returns memory traffic (in bytes) in factorization*/
	__OUT _double_t *scomm			/*returns memory traffic (in bytes) in solving*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_GetFactors: gets LU factors in CSR format                                                 */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_GetFactors
(
	__IN _handle_t ctx,
	__OUT _double_t *lx,			/*length lnz (_double_t or _complex_t), numerical values of L. lnz=stat[9]*/
	__OUT _uint_t *li,				/*length lnz, column indexes of L*/
	__OUT _size_t *lp,				/*length n+1, row pointers of L*/
	__OUT _double_t *ux,			/*length unz (_double_t or _complex_t), numerical values of U. unz=stat[10]*/
	__OUT _uint_t *ui,				/*length unz, column indexes of U*/
	__OUT _size_t *up,				/*length n+1, row pointers of U*/
	__IN _bool_t sort,				/*whether to sort each row of factors*/
	__OUT _uint_t *row_perm,		/*length n, row permutation (can be NULL)*/
	__OUT _uint_t *col_perm,		/*length n, column permutation (can be NULL)*/
	__OUT _double_t *row_scale,		/*length n, row scaling factors (can be NULL)*/
	__OUT _double_t *col_scale		/*length n, column scaling factors (can be NULL)*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_ConditionNumber: estimates condition number                                               */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_ConditionNumber
(
	__IN _handle_t ctx,
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__OUT _double_t *cond			/*returns condition number*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_MemoryUsage: calculates allocatd virtual memory (in bytes)                                */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_MemoryUsage
(
	__IN _handle_t ctx,
	__OUT _size_t *memuse			/*returns used memory (in bytes)*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Performance: estimates the performance                                                    */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_Performance
(
	__IN _handle_t ctx,
	__IN int tsync,					/*cycles of inter-thread sync.*/
	__IN int threads,				/*# of threads*/
	__OUT _double_t *perf			/*length 4. perf[0]: theoretical max speedup; perf[1]: max speedup; 
									perf[2]: ratio of waiting; perf[3]: ratio of sync*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_Determinant: estimates the determinant                                                    */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_Determinant
(
	__IN _handle_t ctx,
	__OUT _double_t *det_coef,		/*_complex_t for complex matrix, returns coefficient part of det*/
	__OUT _double_t *det_exp		/*returns exponent part of det*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_FactorizeMatrix (high level routine): factor or refactor                                  */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_FactorizeMatrix
(
	__IN _handle_t ctx,
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__IN int threads				/*# of threads. Set 0 to use all created threads*/
);

/*-------------------------------------------------------------------------------------------------*/
/*NicsLU_SolveAndRefine (high level routine): solves and refines the solution                      */
/*-------------------------------------------------------------------------------------------------*/
int NicsLU_SolveAndRefine
(
	__IN _handle_t ctx,
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__IN const _double_t *b,		/*length n (_double_t or _complex_t), RHS*/
	__OUT _double_t *x				/*length n (_double_t or _complex_t), solution*/
);

/*-------------------------------------------------------------------------------------------------*/
/*SparseResidual (utility routine): calculates the residual error ||Ax-b||                         */
/*-------------------------------------------------------------------------------------------------*/
int SparseResidual
(
	__IN _uint_t n,					/*matrix dimension*/
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__IN const _uint_t *ai,			/*length ap[n], column indexes*/
	__IN const _uint_t *ap,			/*length n+1, row pointers*/
	__IN const _double_t *b,		/*length n (_double_t or _complex_t), RHS*/
	__IN const _double_t *x,		/*length n (_double_t or _complex_t), solution*/
	__OUT _double_t *res,			/*length 4. res[0]: RMSE; res[1]: L1-norm; res[2]: L2-norm; res[3]: Linf-norm*/
	__IN _matrix_type_t mtype		/*matrix type*/
);

/*-------------------------------------------------------------------------------------------------*/
/*SparseTranspose (utility routine): transposes the matrix                                         */
/*-------------------------------------------------------------------------------------------------*/
int SparseTranspose
(
	__IN _uint_t n,					/*matrix dimension*/
	__INANDOUT _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__INANDOUT _uint_t *ai,			/*length ap[n], column indexes*/
	__INANDOUT _uint_t *ap,			/*length n+1, row pointers*/
	__IN _transpose_t op			/*transposition type*/
);

/*-------------------------------------------------------------------------------------------------*/
/*ReadMatrixMarket (utility routine): reads a file in matrix market format                         */
/*-------------------------------------------------------------------------------------------------*/
/*
Two steps to use this routine.
1. Set ax, ai, and ap to NULL, then row, col, and nnz return their values.
2. Alloc ax, ai, and ap, then read the matrix. If the matrix is a vector, only alloc ax.
*/
int ReadMatrixMarket
(
	__IN const char *file,
	__OUT _uint_t *row,				/*# of rows*/
	__OUT _uint_t *col,				/*# of columns*/
	__OUT _uint_t *nnz,				/*# of nonzeros*/
	__OUT _double_t *ax,			/*length nnz (_double_t or _complex_t), numerical values, in column order*/
	__OUT _uint_t *ai,				/*length nnz, row indexes, in column order. NULL for vector*/
	__OUT _uint_t *ap,				/*length col+1, column pointers. NULL for vector*/
	__IN int is_complex				/*whether the matrix is complex*/
);

/*-------------------------------------------------------------------------------------------------*/
/*SparseHalfToSymmetricFull (utility routine): transform half matrix to symmetric matrix           */
/*-------------------------------------------------------------------------------------------------*/
/*Please pre-allocate memories for aax, aai, and aap.*/
int SparseHalfToSymmetricFull
(
	__IN _uint_t n,					/*matrix dimension*/
	__IN const _double_t *ax,		/*length ap[n] (_double_t or _complex_t), numerical values*/
	__IN const _uint_t *ai,			/*length ap[n], column indexes*/
	__IN const _uint_t *ap,			/*length n+1, row pointers*/
	__OUT _double_t *aax,			/*max length nnz*2 (_double_t or _complex_t), numerical values of resulting matrix*/
	__OUT _uint_t *aai,				/*max length nnz*2, column indexes of resulting matrix*/
	__OUT _uint_t *aap,				/*length n+1, row pointers of resulting matrix*/
	__IN int is_complex				/*whether the matrix is complex*/
);

/*-------------------------------------------------------------------------------------------------*/
/*PrintNicsLULicense (utility routine): prints license information                                 */
/*-------------------------------------------------------------------------------------------------*/
int PrintNicsLULicense
(
	__IN void (*fptr)(const char *)	/*function pointer for output. If it is NULL, default stdout is used*/
);

#ifdef __cplusplus
}
#endif

#endif
