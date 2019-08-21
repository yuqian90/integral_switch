cmake_minimum_required(VERSION 3.7.0)

project(integral_switch VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-Wall -Werror -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


include_directories(${PROJECT_SOURCE_DIR}/include)

enable_testing()

add_subdirectory(${PROJECT_SOURCE_DIR}/test)


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

