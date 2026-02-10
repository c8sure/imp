# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/domino/benchmark
# Build directory: /home/catherine/imp/build/modules/domino/benchmark
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.domino-benchmark_domino2.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/domino/benchmark/domino/benchmark_domino2" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.domino-benchmark_domino2.cpp PROPERTIES  COST "3" LABELS "IMP.domino-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/domino/benchmark/CMakeLists.txt;49;imp_add_tests;/home/catherine/imp/modules/domino/benchmark/CMakeLists.txt;0;")
add_test(IMP.domino-benchmark_domino_container.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/domino/benchmark/domino/benchmark_domino_container" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.domino-benchmark_domino_container.cpp PROPERTIES  COST "3" LABELS "IMP.domino-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/domino/benchmark/CMakeLists.txt;49;imp_add_tests;/home/catherine/imp/modules/domino/benchmark/CMakeLists.txt;0;")
