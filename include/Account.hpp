#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Transaction.hpp"

class Account{
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;
    std::vector<std::shared_ptr<Transaction>> transactions;

public:
    Account(const std::string &accNum, const std::string &ownNm, double initialBalance);
    ~Account() = default;

    void deposit(double amount);
    void withdraw(double amount);
    void transfer(double amount, const std::string &toAccountNumber);
    void displayDetails() const;
    double getBalance() const;
    std::string getOwnerName() const;
    std::string getAccountNumber() const;

    void addTransaction(std::shared_ptr<Transaction> transaction);

    void setOwnerName(const std::string &name);
    void setAccountNumber(const std::string &number);
};