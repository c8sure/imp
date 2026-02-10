# Install script for directory: /home/catherine/imp/modules/core/dependency

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/home/catherine/miniforge3/envs/imp/bin/x86_64-conda-linux-gnu-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "__init__.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/__init__.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "__init__.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/__init__.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "analysis.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/analysis.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "citations.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/citations.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "cross_linkers.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/cross_linkers.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "dataset.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/dataset.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "dumper.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/dumper.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "flr.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/flr.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "format.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/format.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "format_bcif.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/format_bcif.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "geometry.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/geometry.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "location.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/location.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "metadata.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/metadata.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "model.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/model.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "multi_state_scheme.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/multi_state_scheme.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "protocol.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/protocol.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "reader.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/reader.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "reference.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/reference.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "report.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/report.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "representation.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/representation.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "restraint.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/restraint.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "source.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/source.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/__pycache__" TYPE FILE RENAME "startmodel.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/__pycache__/startmodel.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "_format.so" FILES "/home/catherine/imp/build/lib/ihm/_format.so")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "analysis.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/analysis.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "citations.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/citations.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "cross_linkers.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/cross_linkers.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "dataset.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/dataset.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "dictionary.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/dictionary.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "dumper.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/dumper.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "flr.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/flr.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "format.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/format.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "format_bcif.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/format_bcif.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "geometry.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/geometry.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "location.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/location.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "metadata.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/metadata.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "model.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/model.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "multi_state_scheme.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/multi_state_scheme.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "protocol.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/protocol.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "reader.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/reader.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "reference.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/reference.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "report.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/report.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "representation.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/representation.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "restraint.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/restraint.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "source.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/source.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "startmodel.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/startmodel.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE FILE RENAME "test.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/test.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/util" TYPE FILE RENAME "__init__.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/util/__init__.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/util/__pycache__" TYPE FILE RENAME "__init__.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/util/__pycache__/__init__.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/util" TYPE FILE RENAME "make_mmcif.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/util/make_mmcif.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/util" TYPE FILE RENAME "__init__.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/util/__init__.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/util/__pycache__" TYPE FILE RENAME "__init__.cpython-310.pyc" FILES "/home/catherine/imp/build/lib/ihm/util/__pycache__/__init__.cpython-310.pyc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/util" TYPE FILE RENAME "make_mmcif.py" FILES "/home/catherine/imp/modules/core/dependency/python-ihm/ihm/util/make_mmcif.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/_format.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/_format.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/_format.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm" TYPE MODULE FILES "/home/catherine/imp/build/lib/ihm/_format.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/_format.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/_format.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/home/catherine/miniforge3/envs/imp/bin/x86_64-conda-linux-gnu-strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib64/python3.10/site-packages/ihm/_format.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/catherine/imp/build/modules/core/dependency/CMakeFiles/ihm-python.dir/install-cxx-module-bmi-noconfig.cmake" OPTIONAL)
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/catherine/imp/build/modules/core/dependency/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
