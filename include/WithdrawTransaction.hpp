#pragma once
#include <string>
#include "Transaction.hpp"


class WithdrawTransaction : public Transaction{
public:
    WithdrawTransaction(double amt, std::string &accNum);

    std::string getType() const override; 
    void display() const override;
};