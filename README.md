NICSLU----Parallel Sparse Solver for Circuit Simulation
============
About the name of the solver: NICS is the name of our lab in Tsinghua University ---- Nano-scale Integrated Circuits and Systems.

Introduction: NICSLU is a high-performance and robust software package for solving large-scale sparse linear systems of equations (Ax = b) on multi-core shared-memory machines. It is written by C, and can be easily used in C/C++ programs. NICSLU is well suited for SPICE-based circuit simulation problems.

Performance of NICSLU: Sequential NICSLU is about 2-3X (on average) faster than KLU. Parallel NICSLU is about 10X (on average) faster than KLU. When using the same number of threads, NICSLU is about 2X (on average) faster than PARDISO. NICSLU is much faster than UMFPACK and SuperLU. Note that all these speedups are average values based on our evaluations on circuit simulation problems. Please download [results.pdf](https://github.com/chenxm1986/nicslu/blob/master/results.pdf) (from an old version) for the results and comparisons. NICSLU is also proven to be high-performance in several state-of-the-art SPICE-based commercial simulators from several famous EDA companies. Some techniques have been adopted in domestic EDA software.

NICSLU features the following innovatory techniques.  
(1) Better-than-AMD matrix ordering, which reduces about 30-40% floating-point operations than conventional AMD.  
(2) Adaptive numerical kernel selection.  
(3) Low-cost dynamic scheduling for parallel factorization.  
(4) Numerically stable pivoting reduction.  


## License

#### For commercial purpose:

Please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) for commercial licenses. Please also note that the key techniques of NICSLU are protected by Chinese patents.

#### For academic research:

You can use NICSLU for free. Once the license is expired, please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) to get a new license or download a new version. Please cite one or more of our papers when you publish your research if you have used NICSLU in your research.

## Publications

[1] Xiaoming Chen, Yu Wang, Huazhong Yang, Parallel Sparse Direct Solver for Integrated Circuit Simulation", Springer Publishing, 1st edition, Feb. 2017. 136 pages.

[2] Xiaoming Chen, Wei Wu, Yu Wang, Hao Yu, Huazhong Yang, An EScheduler-based Data Dependence Analysis and Task Scheduling for Parallel Circuit Simulation", Circuits and Systems II: Express Briefs, IEEE Transactions on, vol. 58, no. 10, pp. 702-706, oct. 2011.

[3] Xiaoming Chen, Yu Wang, Huazhong Yang, NICSLU: An Adaptive Sparse Matrix Solver for Parallel Circuit Simulation", Computer-Aided Design of Integrated Circuits and Systems, IEEE Transactions on, vol. 32, no. 2, pp. 261-274, feb. 2013.

[4] Xiaoming Chen, Yu Wang, Huazhong Yang, An Adaptive LU Factorization Algorithm for Parallel Circuit Simulation", Design Automation Conference (ASP-DAC), 2012 17th Asia and South Pacific, pp.359-364, Jan. 30, 2012-Feb. 2, 2012.

[5] Xiaoming Chen, Yu Wang, Huazhong Yang, A Fast Parallel Sparse Solver for SPICE-based Circuit Simulators", Design, Automation, and Test in Europe (DATE) 2015, pp.205-210, 9-13 March, 2015.

[6] Xiaoming Chen, Lixue Xia, Yu Wang, Huazhong Yang, Sparsity-Oriented Sparse Solver Design for Circuit Simulation", Design, Automation, and Test in Europe (DATE) 2016, pp.1580-1585, March 14-18, 2016.


## For Use in [Dolphin Design - SMASH](https://support.dolphin-design.fr/index.php/eda_solutions/eda_downloads)

For SMASH 7.5.X, please use the special libraries in nicslu_for_smash7.5.x, while for SMASH 7.6.0, please use nicslu202110.

Put "nicslu.dll", "nicslu.lib", and "nicslu.lic" in the "bin" folder of your SMASH installation path, e.g., "C:\Program Files\Dolphin\Solutions 2019 Q4.1\smash\bin\". Add ".OPTION SOLVER=NICSLU" in your netlist.

Once the license is expired, please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) to get a new license or download a new version.


## By using this software, you agree with the following terms.

#### Warranty Disclaimer

THE SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS AND DEFECTS WITHOUT WARRANTY OF ANY KIND. THE COPYRIGHT HOLDERS EXPRESSLY DISCLAIM ALL WARRANTIES, WHETHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO THE SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND NON-INFRINGEMENT, AND WARRANTIES THAT MAY ARISE OUT OF COURSE OF DEALING, COURSE OF PERFORMANCE, USAGE, OR TRADE PRACTICE. WITHOUT LIMITATION TO THE FOREGOING, THE COPYRIGHT HOLDERS MAKES NO WARRANTY OF ANY KIND THAT THE SOFTWARE WILL MEET ANY PERSON'S REQUIREMENTS, ACHIEVE ANY INTENDED RESULTS, BE COMPATIBLE, OR WORK WITH ANY OTHER SOFTWARE, APPLICATIONS, SYSTEMS, OR SERVICES, OPERATE WITHOUT INTERRUPTION, MEET ANY PERFORMANCE OR RELIABILITY STANDARDS OR BE ERROR FREE, OR THAT ANY ERRORS OR DEFECTS CAN OR WILL BE CORRECTED.


#### Limitations of Liability

IN NO EVENT WILL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR INABILITY TO USE THE SOFTWARE, EVEN IF THE COPYRIGHT HOLDERS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.



Authors
============
Please visit [Xiaoming Chen's personal page](http://people.ucas.edu.cn/~chenxm) or [Yu Wang's group page](https://nicsefc.ee.tsinghua.edu.cn/).
