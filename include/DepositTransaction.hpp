#pragma once
#include <string>
#include "Transaction.hpp"


class DepositTransaction : public Transaction{
public:
    DepositTransaction(double amt, const std::string &accNum);

    std::string getType() const override; 
    void display() const override;
};