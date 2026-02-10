# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/multi_state/test
# Build directory: /home/catherine/imp/build/modules/multi_state/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.multi_state-test_multi_foxs_rpa_example.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/multi_state/test/test_multi_foxs_rpa_example.py")
set_tests_properties(IMP.multi_state-test_multi_foxs_rpa_example.py PROPERTIES  COST "1" LABELS "IMP.multi_state-test-python-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;101;imp_add_python_tests;/home/catherine/imp/modules/multi_state/test/CMakeLists.txt;54;imp_add_tests;/home/catherine/imp/modules/multi_state/test/CMakeLists.txt;0;")
add_test(IMP.multi_state-medium_test_standards.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/build/test/multi_state/medium_test_standards.py")
set_tests_properties(IMP.multi_state-medium_test_standards.py PROPERTIES  COST "2" LABELS "IMP.multi_state-test-python-MEDIUM" TIMEOUT "15" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;102;imp_add_python_tests;/home/catherine/imp/modules/multi_state/test/CMakeLists.txt;54;imp_add_tests;/home/catherine/imp/modules/multi_state/test/CMakeLists.txt;0;")
