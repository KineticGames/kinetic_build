set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(GoogleTest)

macro(add_test test_file)
    get_filename_component(_test_name ${test_file} NAME_WE)
    add_executable(${_test_name} ${test_file})
    target_link_libraries(${_test_name} GTest::gtest_main ${PROJECT_NAME})
    gtest_discover_tests(${_test_name})
endmacro(add_test)
