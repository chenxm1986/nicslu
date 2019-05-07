# Introduction
    About the name of the solver: NICS is the name of our lab in Tsinghua University ---- Nano-scale Integrated Circuits and Systems.
    Introduction: NICSLU is a high-performance, robust and thread-safe software package for solving large-scale sparse linear systems of equations (Ax = b) on multi-core shared-memory machines. It is written by C, and can be easily used in C/C++ programs. NICSLU is well suited for SPICE-based circuit simulation problems. There is no limitation of matrix dimension that NICSLU can handle with two exceptions: 1) your computer memory is not big enough; 2) you are using a 32-bit library.
    Performance of NICSLU: For a category of circuit matrices, sequential NICSLU has similar performance as KLU, while for the rest, sequential NICSLU is faster than KLU. Parallel NICSLU is slightly faster than PARDISO, and much faster than UMFPACK and SuperLU. Note that all these comparisons are only for circuit simulation problems. NICSLU is also proved to be high-performance in several state-of-the-art SPICE-based commercial simulators from several famous EDA companies. 
    Authors' information: Please visit Xiaoming Chen's personal page or Yu Wang's group page.
    
# Publications
[BOOK] Xiaoming Chen, Yu Wang, Huazhong Yang, "Parallel Sparse Direct Solver for Integrated Circuit Simulation". Springer, 1st edition, Feb 2017, 136 pages. (Most of the techniques used in NICSLU are described in this book)
 
1) CPU solver & parallel factorization algorithm
[IEEE TCAD] Xiaoming Chen, Yu Wang, Huazhong Yang, "NICSLU: An Adaptive Sparse Matrix Solver for Parallel Circuit Simulation", Computer-Aided Design of Integrated Circuits and Systems, IEEE Transactions on, vol. 32, no. 2, pp. 261-274, feb. 2013.   
[ASP-DAC’12] Xiaoming Chen, Yu Wang, Huazhong Yang, "An adaptive LU factorization algorithm for parallel circuit simulation", Design Automation Conference (ASP-DAC), 2012 17th Asia and South Pacific, pp.359-364, Jan. 30 2012-Feb. 2 2012. (best paper nomination) 
[DATE’16] Xiaoming Chen, Lixue Xia, Yu Wang, Huazhong Yang, “Sparsity-Oriented Sparse Solver Design for Circuit Simulation”, Design, Automation, and Test in Europe (DATE) 2016, pp.1580-1585, March 14-18, 2016.
 
2) CPU parallel re-factorization
[IEEE TCASII] Xiaoming Chen, Wei Wu, Yu Wang, Hao Yu, Huazhong Yang, "An EScheduler-based Data Dependence Analysis and Task Scheduling for Parallel Circuit Simulation", Circuits and Systems II: Express Briefs, IEEE Transactions on, vol. 58, no. 10, pp. 702 –706, oct. 2011.
 
3) CPU fast factorization
[DATE’15] Xiaoming Chen, Yu Wang, Huazhong Yang, "A Fast Parallel Sparse Solver for SPICE-based Circuit Simulators", Design, Automation, and Test in Europe (DATE) 2015, pp.205-210, 9-13 March 2015.
 
4) GPU parallel re-factorization
[DAC’12] Ling Ren, Xiaoming Chen, Yu Wang, Chenxi Zhang, Huazhong Yang, "Sparse LU factorization for parallel circuit simulation on GPU", In Proceedings of the 49th Annual Design Automation Conference (DAC '12). ACM, New York, NY, USA, 1125-1130.
[IEEE TPDS] Xiaoming Chen, Ling Ren, Yu Wang, Huazhong Yang, “GPU-Accelerated Sparse LU Factorization for Circuit Simulation with Performance Modeling”, IEEE Transactions on Parallel and Distributed Systems (IEEE TPDS), vol.26, no.3, pp.786-795, March 2015.
 
5) GPU blocked algorithm
[IA3’13] Xiaoming Chen, Du Su, Yu Wang, Huazhong Yang, "Nonzero pattern analysis and memory access optimization in GPU-based sparse LU factorization for circuit simulation", In Proceedings of the 3rd Workshop on Irregular Applications: Architectures and Algorithms (IA^3 '13).
