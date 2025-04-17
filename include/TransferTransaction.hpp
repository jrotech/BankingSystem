#pragma once
#include <string>
#include "Transaction.hpp"


class TransferTransaction : public Transaction{
private:
    std::string toAccountNumber;

public:
    TransferTransaction(double amt, std::string &accNum, std::string &toAccNum);

    std::string getType() const override; 
    void display() const override;
    std::string getToAccountNumber() const;
    
};