# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/mpi/examples
# Build directory: /home/catherine/imp/build/modules/mpi/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.mpi-temperature_rem.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/mpi/examples/temperature_rem.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.mpi-temperature_rem.py PROPERTIES  COST "3" LABELS "IMP.mpi-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/mpi/examples/CMakeLists.txt;30;imp_add_tests;/home/catherine/imp/modules/mpi/examples/CMakeLists.txt;0;")
