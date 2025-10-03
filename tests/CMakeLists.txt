add_executable(unit_tests
  account_test.cpp
 
)
target_link_libraries(unit_tests PRIVATE core GTest::gtest GTest::gtest_main)
add_test(NAME unit_tests COMMAND unit_tests)
