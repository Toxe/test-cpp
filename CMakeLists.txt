cmake_minimum_required(VERSION 3.14)
project("C++ Console Test Apps" LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(ALL_TARGETS
    allocator
    bind
    cast
    const
    constexpr
    constructors
    decltype
    enum
    exceptions
    explicit
    fstream
    function_pointers
    initialization
    iterator
    lambda
    optional
    shared_ptr
    string
    structured_binding
    typedef
    unique_ptr
    value_range_observer
    vector
)

foreach(target ${ALL_TARGETS})
    add_executable(${target} ${target}.cpp)
    target_compile_features(${target} PUBLIC cxx_std_17)
    target_compile_options(${target} PRIVATE -Wall -Wextra -Wmost -pedantic -Wconversion -Wfloat-equal -Wold-style-cast)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
endforeach()

target_compile_options(constexpr PRIVATE -Wno-unused-variable)
target_compile_options(decltype PRIVATE -Wno-unused-variable)
target_compile_options(explicit PRIVATE -Wno-unused-private-field -Wno-unused-variable)
target_compile_options(initialization PRIVATE -Wno-unused-variable)
target_compile_options(iterator PRIVATE -Wno-unused-variable)
target_compile_options(typedef PRIVATE -Wno-unused-variable)
