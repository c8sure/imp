# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/cgal/test
# Build directory: /home/catherine/imp/build/modules/cgal/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.cgal-test_bad_sav.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/cgal/test/cgal/test_bad_sav" "--deprecation_exceptions")
set_tests_properties(IMP.cgal-test_bad_sav.cpp PROPERTIES  COST "1" LABELS "IMP.cgal-test-cpp-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;104;imp_add_cpp_tests;/home/catherine/imp/modules/cgal/test/CMakeLists.txt;36;imp_add_tests;/home/catherine/imp/modules/cgal/test/CMakeLists.txt;0;")
add_test(IMP.cgal-test_memory_problem.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/cgal/test/cgal/test_memory_problem" "--deprecation_exceptions")
set_tests_properties(IMP.cgal-test_memory_problem.cpp PROPERTIES  COST "1" LABELS "IMP.cgal-test-cpp-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;104;imp_add_cpp_tests;/home/catherine/imp/modules/cgal/test/CMakeLists.txt;36;imp_add_tests;/home/catherine/imp/modules/cgal/test/CMakeLists.txt;0;")
add_test(IMP.cgal-test_skin_failure.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/cgal/test/cgal/test_skin_failure" "--deprecation_exceptions")
set_tests_properties(IMP.cgal-test_skin_failure.cpp PROPERTIES  COST "1" LABELS "IMP.cgal-test-cpp-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;104;imp_add_cpp_tests;/home/catherine/imp/modules/cgal/test/CMakeLists.txt;36;imp_add_tests;/home/catherine/imp/modules/cgal/test/CMakeLists.txt;0;")
add_test(IMP.cgal-medium_test_standards.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/build/test/cgal/medium_test_standards.py")
set_tests_properties(IMP.cgal-medium_test_standards.py PROPERTIES  COST "2" LABELS "IMP.cgal-test-python-MEDIUM" TIMEOUT "15" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;102;imp_add_python_tests;/home/catherine/imp/modules/cgal/test/CMakeLists.txt;42;imp_add_tests;/home/catherine/imp/modules/cgal/test/CMakeLists.txt;0;")
