# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/score_functor/test
# Build directory: /home/catherine/imp/build/modules/score_functor/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.score_functor-test_functor_distance_pair_scores.cpp "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/imp/build/modules/score_functor/test/score_functor/test_functor_distance_pair_scores" "--deprecation_exceptions")
set_tests_properties(IMP.score_functor-test_functor_distance_pair_scores.cpp PROPERTIES  COST "1" LABELS "IMP.score_functor-test-cpp-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;61;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;104;imp_add_cpp_tests;/home/catherine/imp/modules/score_functor/test/CMakeLists.txt;40;imp_add_tests;/home/catherine/imp/modules/score_functor/test/CMakeLists.txt;0;")
add_test(IMP.score_functor-medium_test_standards.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/build/test/score_functor/medium_test_standards.py")
set_tests_properties(IMP.score_functor-medium_test_standards.py PROPERTIES  COST "2" LABELS "IMP.score_functor-test-python-MEDIUM" TIMEOUT "15" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;102;imp_add_python_tests;/home/catherine/imp/modules/score_functor/test/CMakeLists.txt;46;imp_add_tests;/home/catherine/imp/modules/score_functor/test/CMakeLists.txt;0;")
