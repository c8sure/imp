# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/core/benchmark
# Build directory: /home/catherine/imp/build/modules/core/benchmark
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.core-benchmark_omp_evaluate.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/core/benchmark/core/benchmark_omp_evaluate" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.core-benchmark_omp_evaluate.cpp PROPERTIES  COST "3" LABELS "IMP.core-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/core/benchmark/CMakeLists.txt;39;imp_add_tests;/home/catherine/imp/modules/core/benchmark/CMakeLists.txt;0;")
add_test(IMP.core-benchmark_xyz_access.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/core/benchmark/core/benchmark_xyz_access" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.core-benchmark_xyz_access.cpp PROPERTIES  COST "3" LABELS "IMP.core-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/core/benchmark/CMakeLists.txt;39;imp_add_tests;/home/catherine/imp/modules/core/benchmark/CMakeLists.txt;0;")
