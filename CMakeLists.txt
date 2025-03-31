cmake_minimum_required(VERSION 3.14)
project(PR2_5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../PR2_5/lib/googletest)

include_directories(/opt/homebrew/opt/ncurses/include)
link_directories(/opt/homebrew/opt/ncurses/lib)

add_executable(PR2_5
        classes/RightAngled.h
        classes/RightAngled.cpp
        classes/Triangle.h
        classes/Triangle.cpp
        main.cpp
)

target_link_libraries(PR2_5)

add_executable(PR2_5_tests
        classes/RightAngled.h
        classes/RightAngled.cpp
        classes/Triangle.h
        classes/Triangle.cpp
        tests/tests.cpp
)

target_link_libraries(PR2_5_tests gtest gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(PR2_5_tests)
