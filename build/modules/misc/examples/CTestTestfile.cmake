# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/misc/examples
# Build directory: /home/catherine/imp/build/modules/misc/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.misc-decay.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/misc/examples/decay.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.misc-decay.py PROPERTIES  COST "3" LABELS "IMP.misc-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/misc/examples/CMakeLists.txt;42;imp_add_tests;/home/catherine/imp/modules/misc/examples/CMakeLists.txt;0;")
