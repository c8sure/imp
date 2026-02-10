# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/algebra/examples
# Build directory: /home/catherine/imp/build/modules/algebra/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.algebra-geometry.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/algebra/examples/geometry.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.algebra-geometry.py PROPERTIES  COST "3" LABELS "IMP.algebra-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/algebra/examples/CMakeLists.txt;32;imp_add_tests;/home/catherine/imp/modules/algebra/examples/CMakeLists.txt;0;")
add_test(IMP.algebra-grid_space.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/algebra/examples/grid_space.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.algebra-grid_space.py PROPERTIES  COST "3" LABELS "IMP.algebra-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/algebra/examples/CMakeLists.txt;32;imp_add_tests;/home/catherine/imp/modules/algebra/examples/CMakeLists.txt;0;")
add_test(IMP.algebra-grid.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/algebra/doc/examples/algebra/grid" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.algebra-grid.cpp PROPERTIES  COST "3" LABELS "IMP.algebra-example-cpp-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;106;imp_add_cpp_tests;/home/catherine/imp/modules/algebra/examples/CMakeLists.txt;32;imp_add_tests;/home/catherine/imp/modules/algebra/examples/CMakeLists.txt;0;")
