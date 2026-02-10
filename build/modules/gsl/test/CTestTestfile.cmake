# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/gsl/test
# Build directory: /home/catherine/imp/build/modules/gsl/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.gsl-test_cg_optimizer.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/gsl/test/test_cg_optimizer.py")
set_tests_properties(IMP.gsl-test_cg_optimizer.py PROPERTIES  COST "1" LABELS "IMP.gsl-test-python-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;101;imp_add_python_tests;/home/catherine/imp/modules/gsl/test/CMakeLists.txt;46;imp_add_tests;/home/catherine/imp/modules/gsl/test/CMakeLists.txt;0;")
add_test(IMP.gsl-test_qn_minimizer.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/gsl/test/test_qn_minimizer.py")
set_tests_properties(IMP.gsl-test_qn_minimizer.py PROPERTIES  COST "1" LABELS "IMP.gsl-test-python-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;101;imp_add_python_tests;/home/catherine/imp/modules/gsl/test/CMakeLists.txt;46;imp_add_tests;/home/catherine/imp/modules/gsl/test/CMakeLists.txt;0;")
add_test(IMP.gsl-test_simplex_minimizer.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/gsl/test/test_simplex_minimizer.py")
set_tests_properties(IMP.gsl-test_simplex_minimizer.py PROPERTIES  COST "1" LABELS "IMP.gsl-test-python-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;101;imp_add_python_tests;/home/catherine/imp/modules/gsl/test/CMakeLists.txt;46;imp_add_tests;/home/catherine/imp/modules/gsl/test/CMakeLists.txt;0;")
add_test(IMP.gsl-medium_test_standards.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/build/test/gsl/medium_test_standards.py")
set_tests_properties(IMP.gsl-medium_test_standards.py PROPERTIES  COST "2" LABELS "IMP.gsl-test-python-MEDIUM" TIMEOUT "15" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;102;imp_add_python_tests;/home/catherine/imp/modules/gsl/test/CMakeLists.txt;46;imp_add_tests;/home/catherine/imp/modules/gsl/test/CMakeLists.txt;0;")
