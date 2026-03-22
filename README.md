NICSLU----Parallel Sparse Solver for Circuit Simulation
============
About the name of the solver: NICS is the lab name when I was in Tsinghua University ---- Nano-scale Integrated Circuits and Systems.

Introduction: NICSLU is a high-performance and robust software package for solving large-scale sparse linear systems of equations (Ax = b) on multi-core shared-memory machines. It is written by C, and can be easily used in C/C++ programs. NICSLU is well suited for SPICE-based circuit simulation problems.

NICSLU will no longer be updated or maintained. The last version is provided here. The license has been extended to 9999-99-99.

**The successor of NICSLU is [CKTSO](https://github.com/chenxm1986/cktso), which provides better performance and scalability than NICSLU. Please use CKTSO instead.**



## For Use in [Dolphin Design - SMASH](https://support.dolphin-design.fr/index.php/eda_solutions/eda_downloads)

For SMASH 7.5.X, please use the special libraries in nicslu_for_smash7.5.x, while for SMASH 7.6.0, please use nicslu202110.

Put "nicslu.dll", "nicslu.lib", and "nicslu.lic" in the "bin" folder of your SMASH installation path, e.g., "C:\Program Files\Dolphin\Solutions 2019 Q4.1\smash\bin\". Add ".OPTION SOLVER=NICSLU" in your netlist.



Authors
============
Please visit [Xiaoming Chen's personal page](http://people.ucas.edu.cn/~chenxm) or [Yu Wang's group page](https://nicsefc.ee.tsinghua.edu.cn/).
