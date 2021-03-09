cmake_minimum_required(VERSION 3.13)
project("C++ Console Test Apps" LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# default compiler options and warnings
include(cmake/DefaultCompilerOptionsAndWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

add_subdirectory(src)
