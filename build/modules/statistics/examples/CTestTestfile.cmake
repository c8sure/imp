# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/statistics/examples
# Build directory: /home/catherine/imp/build/modules/statistics/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.statistics-kmeans.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/statistics/examples/kmeans.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.statistics-kmeans.py PROPERTIES  COST "3" LABELS "IMP.statistics-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/statistics/examples/CMakeLists.txt;32;imp_add_tests;/home/catherine/imp/modules/statistics/examples/CMakeLists.txt;0;")
add_test(IMP.statistics-write_a_metric.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/statistics/examples/write_a_metric.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.statistics-write_a_metric.py PROPERTIES  COST "3" LABELS "IMP.statistics-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/statistics/examples/CMakeLists.txt;32;imp_add_tests;/home/catherine/imp/modules/statistics/examples/CMakeLists.txt;0;")
