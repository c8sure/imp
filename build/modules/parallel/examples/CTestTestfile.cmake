# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/parallel/examples
# Build directory: /home/catherine/imp/build/modules/parallel/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.parallel-local_distance.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/parallel/examples/local_distance.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.parallel-local_distance.py PROPERTIES  COST "3" LABELS "IMP.parallel-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/parallel/examples/CMakeLists.txt;28;imp_add_tests;/home/catherine/imp/modules/parallel/examples/CMakeLists.txt;0;")
add_test(IMP.parallel-tasks.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/parallel/examples/tasks.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.parallel-tasks.py PROPERTIES  COST "3" LABELS "IMP.parallel-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/parallel/examples/CMakeLists.txt;28;imp_add_tests;/home/catherine/imp/modules/parallel/examples/CMakeLists.txt;0;")
