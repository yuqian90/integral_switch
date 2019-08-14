SET(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Do not build google benchmark tests")
SET(gtest_build_tests OFF CACHE BOOL "Do not build gtest tests")

#google-benchmark/google-test dependencies
add_subdirectory(extern/benchmark)
add_subdirectory(extern/googletest)

add_executable(simple_test simple_test.cpp)
target_link_libraries(simple_test gtest_main pthread)
add_test(NAME simple_test COMMAND ${PROJECT_BINARY_DIR}/test/simple_test)
