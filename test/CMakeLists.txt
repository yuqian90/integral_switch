# Copyright (C) 2019  Qian Yu
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
