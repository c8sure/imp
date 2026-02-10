# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "lib/RMF.py"
  "lib/RMFPYTHON_wrap.cxx"
  "lib/RMF_HDF5.py"
  "lib/RMF_HDF5PYTHON_wrap.cxx"
  )
endif()
