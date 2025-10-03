#include "Account.hpp"

#include <gtest/gtest.h>

TEST(Account, StartsWithZero) {
    Account a{/*id*/ 1, /*name*/ "alice"};
    EXPECT_DOUBLE_EQ(a.getBalance(), 0.0);
}
