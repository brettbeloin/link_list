cmake_minimum_required(VERSION 3.20)
project(linked_lists CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/doctest)

add_executable(linked_lists)

target_sources(linked_lists PRIVATE
    src/main.cpp
    )

add_executable(tests
    tests/single_test.cpp
    tests/double_test.cpp)
target_include_directories(tests PRIVATE src external/doctest/doctest)
target_link_libraries(tests PRIVATE doctest_with_main)

enable_testing()
add_test(NAME linked_list_tests COMMAND tests)
