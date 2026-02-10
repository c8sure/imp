# CMake generated Testfile for 
# Source directory: /home/catherine/imp/modules/mpi/test
# Build directory: /home/catherine/imp/build/modules/mpi/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IMP.mpi-test_ReplicaExchange.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/mpiexec" "-n" "2" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/modules/mpi/test/test_ReplicaExchange.py")
set_tests_properties(IMP.mpi-test_ReplicaExchange.py PROPERTIES  COST "1" LABELS "IMP.mpi-test-python-CHEAP" TIMEOUT "5" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;101;imp_add_python_tests;/home/catherine/imp/modules/mpi/test/CMakeLists.txt;42;imp_add_tests;/home/catherine/imp/modules/mpi/test/CMakeLists.txt;0;")
add_test(IMP.mpi-medium_test_standards.py "/home/catherine/imp/build/setup_environment.sh" "/home/catherine/miniforge3/envs/imp/bin/mpiexec" "-n" "2" "/home/catherine/miniforge3/envs/imp/bin/python3.10" "/home/catherine/imp/build/test/mpi/medium_test_standards.py")
set_tests_properties(IMP.mpi-medium_test_standards.py PROPERTIES  COST "2" LABELS "IMP.mpi-test-python-MEDIUM" TIMEOUT "15" _BACKTRACE_TRIPLES "/home/catherine/imp/cmake_modules/IMPAddTests.cmake;28;add_test;/home/catherine/imp/cmake_modules/IMPAddTests.cmake;102;imp_add_python_tests;/home/catherine/imp/modules/mpi/test/CMakeLists.txt;42;imp_add_tests;/home/catherine/imp/modules/mpi/test/CMakeLists.txt;0;")
