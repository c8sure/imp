# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/spatiotemporal/examples
# Build directory: /home/catherine/imp/build/modules/spatiotemporal/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.spatiotemporal-Simple_spatiotemporal_example.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/spatiotemporal/examples/toy/Simple_spatiotemporal_example.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.spatiotemporal-Simple_spatiotemporal_example.py PROPERTIES  COST "3" LABELS "IMP.spatiotemporal-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/spatiotemporal/examples/CMakeLists.txt;28;imp_add_tests;/home/catherine/imp/modules/spatiotemporal/examples/CMakeLists.txt;0;")
