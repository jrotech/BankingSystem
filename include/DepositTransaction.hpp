#pragma once
#include <string>
#include "Transaction.hpp"


class DepositTransaction : public Transaction{
public:
    DepositTransaction(double amt, std::string &accNum);

    std::string getType() const override; 
    std::string display() const override;
};