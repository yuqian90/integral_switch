SET(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Do not build google benchmark tests")
SET(gtest_build_tests OFF CACHE BOOL "Do not build gtest tests")

#google-benchmark/google-test dependencies
add_subdirectory(extern/benchmark)
add_subdirectory(extern/googletest)

add_executable(example_test example_test.cpp)
target_link_libraries(example_test PRIVATE gtest_main pthread)
add_test(NAME example_test COMMAND ${PROJECT_BINARY_DIR}/test/example_test)

add_executable(switch_test switch_test.cpp)
target_link_libraries(switch_test PRIVATE gtest_main pthread)
add_test(NAME switch_test COMMAND ${PROJECT_BINARY_DIR}/test/switch_test)
