# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/pmi/benchmark
# Build directory: /home/catherine/imp/build/modules/pmi/benchmark
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.pmi-benchmark_loop_reconstruction.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/pmi/benchmark/benchmark_loop_reconstruction.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.pmi-benchmark_loop_reconstruction.py PROPERTIES  COST "3" LABELS "IMP.pmi-benchmark-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/pmi/benchmark/CMakeLists.txt;45;imp_add_tests;/home/catherine/imp/modules/pmi/benchmark/CMakeLists.txt;0;")
add_test(IMP.pmi-benchmark_replica_exchange.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/pmi/benchmark/benchmark_replica_exchange.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.pmi-benchmark_replica_exchange.py PROPERTIES  COST "3" LABELS "IMP.pmi-benchmark-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/pmi/benchmark/CMakeLists.txt;45;imp_add_tests;/home/catherine/imp/modules/pmi/benchmark/CMakeLists.txt;0;")
