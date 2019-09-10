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

project(integral_switch VERSION 0.1.0 LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL "integral_switch")
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    option(INTEGRAL_SWITCH_ENABLE_TESTING "Build integral_switch tests" ON)
else()
    option(INTEGRAL_SWITCH_ENABLE_TESTING "Build integral_switch tests" OFF)
endif()

option(INTEGRAL_SWITCH_PERF "Enable perf flags" OFF)
if(INTEGRAL_SWITCH_PERF)
    set(CMAKE_CXX_FLAGS "-fno-omit-frame-pointer")
    link_libraries(profiler)
endif()

if(INTEGRAL_SWITCH_ENABLE_TESTING)
    enable_testing()
    add_subdirectory(${PROJECT_SOURCE_DIR}/test)
endif()

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
        ${PROJECT_SOURCE_DIR}/script/lint.py --clangtidybin ${CLANG_TIDY_BIN} --build-path ${PROJECT_BINARY_DIR} --clangformatbin ${CLANG_FORMAT_BIN} "${PROJECT_SOURCE_DIR}/test/test*.cpp")

    add_custom_target(
        lint
        COMMAND ${LINT_COMMAND}
        COMMENT "Running lint.py"
    )
endif()

add_library(integral_switch INTERFACE)
target_include_directories(integral_switch INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

# Export and install
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    integral_switch-config-version.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion
)

export(
    TARGETS integral_switch NAMESPACE integral_switch::
    FILE integral_switch-targets.cmake
)

install(TARGETS integral_switch EXPORT integral_switch INCLUDES DESTINATION include)

install(
    EXPORT integral_switch
    FILE integral_switch-targets.cmake
    NAMESPACE integral_switch::
    DESTINATION lib/cmake/integral_switch
)

install(DIRECTORY include DESTINATION include)

configure_file(integral_switch-config.cmake.in integral_switch-config.cmake @ONLY)
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/integral_switch-config.cmake"
          "${CMAKE_CURRENT_BINARY_DIR}/integral_switch-config-version.cmake"
    DESTINATION lib/cmake/integral_switch
)
