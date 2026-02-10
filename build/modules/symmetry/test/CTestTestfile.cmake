# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/symmetry/test
# Build directory: /home/catherine/imp/build/modules/symmetry/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.symmetry-test_ball_mover.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/symmetry/test/test_ball_mover.py")
set_tests_properties(IMP.symmetry-test_ball_mover.py PROPERTIES  COST "1" LABELS "IMP.symmetry-test-python-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;101;imp_add_python_tests;/home/catherine/imp/modules/symmetry/test/CMakeLists.txt;48;imp_add_tests;/home/catherine/imp/modules/symmetry/test/CMakeLists.txt;0;")
add_test(IMP.symmetry-medium_test_standards.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/build/test/symmetry/medium_test_standards.py")
set_tests_properties(IMP.symmetry-medium_test_standards.py PROPERTIES  COST "2" LABELS "IMP.symmetry-test-python-MEDIUM" TIMEOUT "15" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;102;imp_add_python_tests;/home/catherine/imp/modules/symmetry/test/CMakeLists.txt;48;imp_add_tests;/home/catherine/imp/modules/symmetry/test/CMakeLists.txt;0;")
