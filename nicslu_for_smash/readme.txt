Put "nicslu.dll", "nicslu.lib", and "nicslu.lic" in the "bin" folder of your SMASH installation path, e.g., "C:\Program Files\Dolphin\Solutions 2019 Q4.1\smash\bin". Add ".OPTION SOLVER=NICSLU" in your netlist.

From version 202006, we provide NICSLU libraries that use or do not use fused-multiply-add (FMA) intrinsic instructions. FMA is supported only by CPU architectures not older than Intel's Haswell (the 4th Core family) or AMD's Piledriver. NicsLU_Initialize checks whether your CPU supports such intrinsics and returns -15 if not. For the case of nonsupport, please use the FMA-disabled libraries and the cost is a small performance degradation.

From version 202006, the license key format is incompatible with previous versions.