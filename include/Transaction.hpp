#pragma once
#include <string>

class Transaction{
private:
    static int nextID; //used for transactionID
    int transactionID;
    double amount;
    std::string timestamp;
    std::string accountNumber;

public:
    Transaction(double amt, std::string &accNum);
    virtual ~Transaction() = default;

    virtual std::string getType() const = 0; //pure virtual
    virtual std::string display() const = 0;
};