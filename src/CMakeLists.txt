set(ALL_TARGETS
    # allocator
    bind
    cast
    chrono
    const
    constexpr
    constructors
    copy_assignment_operator
    copy_constructor
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
    random
    random_discrete_distribution
    random_piecewise_linear_distribution
    shared_ptr
    source_location_function_name
    string
    structured_binding
    typedef
    unique_ptr
    value_range_observer
    variant
    vector
)

foreach(target ${ALL_TARGETS})
    add_executable(${target} ${target}.cpp)
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
    target_compile_features(${target} PUBLIC cxx_std_20)
    target_compile_options(${target} PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})
    target_link_libraries(${target} PRIVATE ${SANITIZER_FLAGS})
endforeach()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(constexpr PRIVATE -Wno-unused-variable)
    target_compile_options(copy_constructor PRIVATE -Wno-vexing-parse)
    target_compile_options(decltype PRIVATE -Wno-unused-variable)
    target_compile_options(explicit PRIVATE -Wno-unused-private-field -Wno-unused-variable)
    target_compile_options(initialization PRIVATE -Wno-unused-variable)
    target_compile_options(iterator PRIVATE -Wno-unused-variable)
    target_compile_options(typedef PRIVATE -Wno-unused-variable)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(constexpr PRIVATE -Wno-unused-variable)
    target_compile_options(decltype PRIVATE -Wno-unused-variable)
    target_compile_options(explicit PRIVATE -Wno-unused-but-set-variable)
    target_compile_options(initialization PRIVATE -Wno-unused-variable)
    target_compile_options(iterator PRIVATE -Wno-unused-but-set-variable)
    target_compile_options(typedef PRIVATE -Wno-unused-variable)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    # target_compile_options(allocator PRIVATE /D_SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING)
    target_compile_options(constexpr PRIVATE /wd4189)
    target_compile_options(decltype PRIVATE /wd4189)
    target_compile_options(initialization PRIVATE /wd4189)
    target_compile_options(typedef PRIVATE /wd4189)
endif()
