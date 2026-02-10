# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/rotamer/test
# Build directory: /home/catherine/imp/build/modules/rotamer/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.rotamer-test_rotamer_angle_tuple.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/rotamer/test/test_rotamer_angle_tuple.py")
set_tests_properties(IMP.rotamer-test_rotamer_angle_tuple.py PROPERTIES  COST "1" LABELS "IMP.rotamer-test-python-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;101;imp_add_python_tests;/home/catherine/imp/modules/rotamer/test/CMakeLists.txt;54;imp_add_tests;/home/catherine/imp/modules/rotamer/test/CMakeLists.txt;0;")
add_test(IMP.rotamer-test_rotamer_library.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/rotamer/test/test_rotamer_library.py")
set_tests_properties(IMP.rotamer-test_rotamer_library.py PROPERTIES  COST "1" LABELS "IMP.rotamer-test-python-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;101;imp_add_python_tests;/home/catherine/imp/modules/rotamer/test/CMakeLists.txt;54;imp_add_tests;/home/catherine/imp/modules/rotamer/test/CMakeLists.txt;0;")
add_test(IMP.rotamer-medium_test_standards.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/build/test/rotamer/medium_test_standards.py")
set_tests_properties(IMP.rotamer-medium_test_standards.py PROPERTIES  COST "2" LABELS "IMP.rotamer-test-python-MEDIUM" TIMEOUT "15" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;102;imp_add_python_tests;/home/catherine/imp/modules/rotamer/test/CMakeLists.txt;54;imp_add_tests;/home/catherine/imp/modules/rotamer/test/CMakeLists.txt;0;")
