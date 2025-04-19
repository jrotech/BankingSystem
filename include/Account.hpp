#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Transaction.hpp"
#include "Bank.hpp"

class Account{
private:
    std::string accountNumber;
    std::string ownerName;
    double balance;
    double interest;
    std::vector<std::shared_ptr<Transaction>> transactions;

public:
    Account(const std::string &accNum, const std::string &ownNm, double initialBalance, double rate=0.025);
    ~Account() = default;

    void deposit(double amount);
    void virtual withdraw(double amount);
    void virtual applyInterest();
    void transfer(const std::shared_ptr<Bank> &bank, double amount, const std::string &toAccountNumber);
    void displayDetails() const;
    
    double getBalance() const;
    std::string getOwnerName() const;
    std::string getAccountNumber() const;

    void addTransaction(std::shared_ptr<Transaction> transaction);

    void setOwnerName(const std::string &name);
    void setAccountNumber(const std::string &number);
};