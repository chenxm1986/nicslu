NICSLU----Parallel Sparse Solver for Circuit Simulation
============
About the name of the solver: NICS is the name of our lab in Tsinghua University ---- Nano-scale Integrated Circuits and Systems.

Introduction: NICSLU is a high-performance and robust software package for solving large-scale sparse linear systems of equations (Ax = b) on multi-core shared-memory machines. It is written by C, and can be easily used in C/C++ programs. NICSLU is well suited for SPICE-based circuit simulation problems.

Performance of NICSLU: Sequential NICSLU is about 2X faster than KLU. Parallel NICSLU is about 10X faster than KLU. When using the same number of threads, NICSLU is 1.5-2X faster than PARDISO. NICSLU is much faster than UMFPACK and SuperLU. Note that all these speedups are average values based on our evaluations on circuit simulation problems. Please download [results.pdf](https://github.com/chenxm1986/nicslu/blob/master/results.pdf) for the results and comparisons. NICSLU is also proven to be high-performance in several state-of-the-art SPICE-based commercial simulators from several famous EDA companies.


## License

#### For commercial purpose:

Please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) for commercial licenses. Please also note that the key techniques of NICSLU are protected by Chinese patents.

#### For academic research:

You can use NICSLU for free. Once the license is expired, please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) to get a new license or download a new version. Please cite one or more of our papers when you publish your research if you have used NICSLU in your research.


## For Use in [Dolphin Design - SMASH](https://support.dolphin-design.fr/index.php/eda_solutions/eda_downloads)

Put "nicslu.dll", "nicslu.lib", and "nicslu.lic" in the "bin" folder of your SMASH installation path, e.g., "C:\Program Files\Dolphin\Solutions 2019 Q4.1\smash\bin\". Please use the 64-bit libraries from the "libs/lib64" folder. DON'T use the int64 libraries. Add ".OPTION SOLVER=NICSLU" in your netlist.

Once the license is expired, please contact [Xiaoming Chen](mailto:chenxiaoming@ict.ac.cn) to get a new license or download a new version.


## By using this software, you agree with the following terms.

#### Warranty Disclaimer

THE SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS AND DEFECTS WITHOUT WARRANTY OF ANY KIND. THE COPYRIGHT HOLDERS EXPRESSLY DISCLAIM ALL WARRANTIES, WHETHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO THE SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND NON-INFRINGEMENT, AND WARRANTIES THAT MAY ARISE OUT OF COURSE OF DEALING, COURSE OF PERFORMANCE, USAGE, OR TRADE PRACTICE. WITHOUT LIMITATION TO THE FOREGOING, THE COPYRIGHT HOLDERS MAKES NO WARRANTY OF ANY KIND THAT THE SOFTWARE WILL MEET ANY PERSON'S REQUIREMENTS, ACHIEVE ANY INTENDED RESULTS, BE COMPATIBLE, OR WORK WITH ANY OTHER SOFTWARE, APPLICATIONS, SYSTEMS, OR SERVICES, OPERATE WITHOUT INTERRUPTION, MEET ANY PERFORMANCE OR RELIABILITY STANDARDS OR BE ERROR FREE, OR THAT ANY ERRORS OR DEFECTS CAN OR WILL BE CORRECTED.


#### Limitations of Liability

IN NO EVENT WILL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR INABILITY TO USE THE SOFTWARE, EVEN IF THE COPYRIGHT HOLDERS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.



Authors
============
Please visit [Xiaoming Chen's personal page](http://people.ucas.edu.cn/~chenxm) or [Yu Wang's group page](https://nicsefc.ee.tsinghua.edu.cn/).
