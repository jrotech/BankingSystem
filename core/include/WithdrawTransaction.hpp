#pragma once
#include "Transaction.hpp"

#include <string>

class WithdrawTransaction : public Transaction {
  public:
    WithdrawTransaction(double amt, const std::string& accNum);

    std::string getType() const override;
    void display() const override;
};