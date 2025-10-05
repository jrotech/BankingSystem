#include "Account.hpp"

#include <gtest/gtest.h>

TEST(Account, StartsWithZero) {
    Account a{/*accNum*/ "1", /*name*/ "alice", /*initialBalance*/ 0.0, /*rate*/ 0.025};
    EXPECT_DOUBLE_EQ(a.getBalance(), 0.0);
}
