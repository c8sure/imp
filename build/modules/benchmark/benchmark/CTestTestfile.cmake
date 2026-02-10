# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/benchmark/benchmark
# Build directory: /home/catherine/imp/build/modules/benchmark/benchmark
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.benchmark-benchmark_nothing.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/benchmark/benchmark/benchmark/benchmark_nothing" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.benchmark-benchmark_nothing.cpp PROPERTIES  COST "3" LABELS "IMP.benchmark-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/benchmark/benchmark/CMakeLists.txt;31;imp_add_tests;/home/catherine/imp/modules/benchmark/benchmark/CMakeLists.txt;0;")
