add_test([=[Tests.TriangleTest]=]  [==[/Users/yura_kulakovskyi/Documents/C++/OOP/PR2/PR2_5/cmake-build-debug/PR2_5_tests]==] [==[--gtest_filter=Tests.TriangleTest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Tests.TriangleTest]=]  PROPERTIES WORKING_DIRECTORY [==[/Users/yura_kulakovskyi/Documents/C++/OOP/PR2/PR2_5/cmake-build-debug]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  PR2_5_tests_TESTS Tests.TriangleTest)
