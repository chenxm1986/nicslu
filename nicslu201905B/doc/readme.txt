License for research purpose only. Expires on 2020-06-30. Contact Xiaoming Chen for a new license or download a new version once expired.

Four demos are provided. demo_real.c and demo_complex.c demonstrate basic usage of NICSLU for real and complex numbers respectively. demo.c and demo.cpp demonstrates a more practical usage of NICSLU using the C interface and C++ wrapper, respectively. To run the demos, please put "nicslu.dll" (from lib32) and "nicslu.lic" together with the exe file.

Please read faq.pdf for some very common questions. These questions help you understand how to use NICSLU and some potential problems you may meet.

To use lib64_int64, you must define the macro __NICS_INT64. Please define the macro __NICS_INT64 by the compiler (this will ensure that this macro is seen by any code), instead of in any C code.

NICSLU DLLs require Windows XP SP3 or higher version Windows.
