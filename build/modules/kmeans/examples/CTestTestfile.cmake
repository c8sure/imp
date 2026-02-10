# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/kmeans/examples
# Build directory: /home/catherine/imp/build/modules/kmeans/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.kmeans-kmeans_example.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/kmeans/examples/kmeans_example.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.kmeans-kmeans_example.py PROPERTIES  COST "3" LABELS "IMP.kmeans-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/kmeans/examples/CMakeLists.txt;28;imp_add_tests;/home/catherine/imp/modules/kmeans/examples/CMakeLists.txt;0;")
