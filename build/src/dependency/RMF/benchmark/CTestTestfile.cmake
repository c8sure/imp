# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/rmf/dependency/RMF/benchmark
# Build directory: /home/catherine/imp/build/src/dependency/RMF/benchmark
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RMF-benchmark_rmf.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/rmf/dependency/RMF/benchmark/benchmark_rmf.py")
set_tests_properties(RMF-benchmark_rmf.py PROPERTIES  COST "3" ENVIRONMENT "PYTHONPATH=/home/catherine/imp/build/lib" LABELS "RMF-benchmark-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/rmf/dependency/RMF/benchmark/CMakeLists.txt;9;imp_add_tests;/home/catherine/imp/modules/rmf/dependency/RMF/benchmark/CMakeLists.txt;0;")
add_test(RMF-benchmark_rmf.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/src/dependency/RMF/benchmark/benchmark_rmf")
set_tests_properties(RMF-benchmark_rmf.cpp PROPERTIES  COST "3" ENVIRONMENT "PYTHONPATH=/home/catherine/imp/build/lib" LABELS "RMF-benchmark-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/rmf/dependency/RMF/benchmark/CMakeLists.txt;9;imp_add_tests;/home/catherine/imp/modules/rmf/dependency/RMF/benchmark/CMakeLists.txt;0;")
