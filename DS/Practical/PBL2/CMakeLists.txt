cmake_minimum_required(VERSION 3.15)

project(sorting_benchmark LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(sorting_benchmark sorting_benchmark.c)

if(MSVC)
    target_compile_options(sorting_benchmark PRIVATE /W4)
else()
    target_compile_options(sorting_benchmark PRIVATE -O2 -Wall -Wextra)
endif()

# Convenience targets that operate in the source directory so that results.csv
# and results.xlsx are produced next to the sources.
add_custom_target(run
    COMMAND $<TARGET_FILE:sorting_benchmark>
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS sorting_benchmark
    USES_TERMINAL)

find_package(Python3 COMPONENTS Interpreter QUIET)
if(Python3_Interpreter_FOUND)
    add_custom_target(report
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/generate_report.py
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        DEPENDS sorting_benchmark
        USES_TERMINAL)
else()
    message(STATUS "Python3 not found - the 'report' target is unavailable.")
endif()
