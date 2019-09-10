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

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Do not build google benchmark tests")
set(gtest_build_tests OFF CACHE BOOL "Do not build gtest tests")

#google-benchmark/google-test dependencies
add_subdirectory(extern/benchmark extern/benchmark EXCLUDE_FROM_ALL)
add_subdirectory(extern/googletest extern/googletest EXCLUDE_FROM_ALL)

macro(add_integral_switch_test TESTNAME)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} PRIVATE gtest_main pthread integral_switch)
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER test)
endmacro()

add_integral_switch_test(test_example test_example.cpp)

add_integral_switch_test(test_switch test_switch.cpp)

add_integral_switch_test(test_dispatch test_dispatch.cpp)

add_integral_switch_test(test_serializer_example test_serializer_example.cpp)

add_executable(benchmark_switch benchmark_switch.cpp)
target_link_libraries(benchmark_switch PRIVATE benchmark_main integral_switch)
add_test(NAME benchmark_switch COMMAND benchmark_switch)
set_target_properties(benchmark_switch PROPERTIES FOLDER test)
