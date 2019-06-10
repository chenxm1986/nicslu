NICSLU----Parallel Sparse Solver for Circuit Simulation
============
About the name of the solver: NICS is the name of our lab in Tsinghua University ---- Nano-scale Integrated Circuits and Systems.<br>

Introduction: NICSLU is a high-performance and robust software package for solving large-scale sparse linear systems of equations (Ax = b) on multi-core shared-memory machines. It is written by C, and can be easily used in C/C++ programs. NICSLU is well suited for SPICE-based circuit simulation problems. There is no limitation of matrix dimension that NICSLU can handle with two exceptions: 1) your computer memory is not big enough; 2) you are using a 32-bit library.<br>

Performance of NICSLU: Sequential NICSLU is about 2X faster than KLU. Parallel NICSLU is about 10X faster than KLU. NICSLU is 1.5-2X faster than PARDISO. NICSLU is much faster than UMFPACK and SuperLU. Note that all these speedups are average values based on our evaluations on circuit simulation problems. Please download [results.pdf](https://github.com/chenxm1986/nicslu/blob/master/results.pdf) for the results. NICSLU is also proved to be high-performance in several state-of-the-art SPICE-based commercial simulators from several famous EDA companies. <br>

This library provides Windows-based DLLs. If you need Linux libraries, please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) with your detailed system information. <br>

Authors' information: Please visit [Xiaoming Chen's personal page](http://people.ucas.edu.cn/~chenxm) or [Yu Wang's group page](https://nicsefc.ee.tsinghua.edu.cn/).
<br><br>

## License

#### For commercial purpose:

Please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) for commercial licenses. Please also note that the key techniques of NICSLU are protected by Chinese patents.<br>

#### For academic research:

You can use NICSLU for free. Once the license is expired, please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) to get a new license or download a new version. Please cite one or more of our papers when you publish your research if you have used NICSLU in your research.

NICSLU-OPEN
============
NICSLU-OPEN is a basic and open-source version of NICSLU. NICSLU-OPEN only has the basic parallel factorization feature of NICSLU, but does not have many new features including parallel supernodal factorization, pivoting reduction, approximate minimum fill-in ordering, etc. NICSLU-OPEN has separated real number and complex number inferfaces.

The last update of NICSLU-OPEN is in Aug 2013. It has known bugs. But we will not update NICSLU-OPEN any more. Please see https://github.com/chenxm1986/nicslu-open.

NICSLU-OPEN is released under the GNU LGPL lincense.
