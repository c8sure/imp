# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/pepdock/test
# Build directory: /home/catherine/imp/build/modules/pepdock/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.pepdock-medium_test_standards.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/build/test/pepdock/medium_test_standards.py")
set_tests_properties(IMP.pepdock-medium_test_standards.py PROPERTIES  COST "2" LABELS "IMP.pepdock-test-python-MEDIUM" TIMEOUT "15" _BACKTRACE_TRIPLES "/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/modules/rmf/dependency/RMF/cmake_modules/IMPAddTests.cmake;102;imp_add_python_tests;/home/catherine/imp/modules/pepdock/test/CMakeLists.txt;58;imp_add_tests;/home/catherine/imp/modules/pepdock/test/CMakeLists.txt;0;")
