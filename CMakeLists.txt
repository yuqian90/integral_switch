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

cmake_minimum_required(VERSION 3.7.0)

project(integral_switch VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-Wall -Werror -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include_directories(${PROJECT_SOURCE_DIR}/include)

enable_testing()

add_subdirectory(${PROJECT_SOURCE_DIR}/test)

option(INTEGRAL_SWITCH_LINT "Do lint" OFF)
if(INTEGRAL_SWITCH_LINT)
    find_program(CLANG_TIDY_BIN clang-tidy-6.0)
    find_program(CLANG_FORMAT_BIN clang-format-6.0)

    if(CLANG_TIDY_BIN STREQUAL "CLANG_TIDY_BIN-NOTFOUND")
        message(FATAL_ERROR "unable to locate clang-tidy-6.0")
    endif()

    if(CLANG_FORMAT_BIN STREQUAL "CLANG_FORMAT_BIN-NOTFOUND")
        message(FATAL_ERROR "unable to locate clang-format-6.0")
    endif()

    list(APPEND LINT_COMMAND
        ${PROJECT_SOURCE_DIR}/script/lint.py --clangtidybin ${CLANG_TIDY_BIN} --build-path ${PROJECT_BINARY_DIR} --clangformatbin ${CLANG_FORMAT_BIN} "${PROJECT_SOURCE_DIR}/include/*.h" "${PROJECT_SOURCE_DIR}/test/*.cpp")

    message("${LINT_COMMAND}")
    add_custom_target(
        lint
        COMMAND ${LINT_COMMAND}
        COMMENT "Running lint.py"
    )
endif()

