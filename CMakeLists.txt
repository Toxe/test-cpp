cmake_minimum_required(VERSION 3.18)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project("C++ Console Test Apps" LANGUAGES CXX)

# testing settings
#include(cmake/Testing.cmake)

# adjust or override some CMake defaults
include(cmake/OverrideCMakeDefaults.cmake)

# default compiler options and warnings
include(cmake/DefaultCompilerOptions.cmake)
include(cmake/DefaultCompilerWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

add_subdirectory(src)
