# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/rmf/benchmark
# Build directory: /home/catherine/imp/build/modules/rmf/benchmark
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.rmf-benchmark_brownian.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/rmf/benchmark/rmf/benchmark_brownian" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.rmf-benchmark_brownian.cpp PROPERTIES  COST "3" LABELS "IMP.rmf-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/rmf/benchmark/CMakeLists.txt;47;imp_add_tests;/home/catherine/imp/modules/rmf/benchmark/CMakeLists.txt;0;")
add_test(IMP.rmf-benchmark_load.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/rmf/benchmark/rmf/benchmark_load" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.rmf-benchmark_load.cpp PROPERTIES  COST "3" LABELS "IMP.rmf-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/rmf/benchmark/CMakeLists.txt;47;imp_add_tests;/home/catherine/imp/modules/rmf/benchmark/CMakeLists.txt;0;")
add_test(IMP.rmf-benchmark_save.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/rmf/benchmark/rmf/benchmark_save" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.rmf-benchmark_save.cpp PROPERTIES  COST "3" LABELS "IMP.rmf-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/rmf/benchmark/CMakeLists.txt;47;imp_add_tests;/home/catherine/imp/modules/rmf/benchmark/CMakeLists.txt;0;")
