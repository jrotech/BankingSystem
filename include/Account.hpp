#pragma once
#include <string>

class Account{
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;
public:
    Account(const std::string &accNum, const std::string &ownNm, double initialBalance);
    ~Account() = default;

    void deposit(double amount);
    void withdraw(double amount);
    void displayDetails() const;
    double getBalance() const;
    std::string getOwnerName() const;
    std::string getAccountNumber() const;
    void setBalance(double newBalance);
    void setOwnerName(const std::string &name);
    void setAccountNumber(const std::string &number);


};