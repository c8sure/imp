# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/rotamer/examples
# Build directory: /home/catherine/imp/build/modules/rotamer/examples
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.rotamer-rotamer_pdb.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/rotamer/examples/rotamer_pdb.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.rotamer-rotamer_pdb.py PROPERTIES  COST "3" LABELS "IMP.rotamer-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/rotamer/examples/CMakeLists.txt;42;imp_add_tests;/home/catherine/imp/modules/rotamer/examples/CMakeLists.txt;0;")
add_test(IMP.rotamer-rotamer_pdb2.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/rotamer/examples/rotamer_pdb2.py" "--run_quick_test" "--deprecation_exceptions")
set_tests_properties(IMP.rotamer-rotamer_pdb2.py PROPERTIES  COST "3" LABELS "IMP.rotamer-example-python-EXPENSIVE" TIMEOUT "120" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;103;imp_add_python_tests;/home/catherine/imp/modules/rotamer/examples/CMakeLists.txt;42;imp_add_tests;/home/catherine/imp/modules/rotamer/examples/CMakeLists.txt;0;")
