#pragma once
#include "Transaction.hpp"

#include <string>

class DepositTransaction : public Transaction {
  public:
    DepositTransaction(double amt, const std::string& accNum);

    std::string getType() const override;
    void display() const override;
};