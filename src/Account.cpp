#include "Account.hpp"
#include <iostream>
#include <memory>
#include "DepositTransaction.hpp"
#include "WithdrawTransaction.hpp"
#include "TransferTransaction.hpp"

//Constructor
Account::Account(const std::string &accNum, const std::string &ownNm, double initialBalance)
    : accountNumber(accNum), ownerName(ownNm), balance(initialBalance) {}

//Add Transaction
void Account::addTransaction(std::shared_ptr<Transaction> transaction){
    transactions.push_back(transaction);
}

//Deposit
void Account::deposit(double amount){
    if (amount >= 0){
        balance += amount;
        std::cout<<"You deposited $" << amount << ". Your balance is now: $" << balance <<"\n";
        std::shared_ptr<DepositTransaction> tx =  std::make_shared<DepositTransaction>(amount,accountNumber);
        addTransaction(tx);
    }
    else
        std::cout<<"You cannot deposit a negative account\n";
}

//Withdraw
void Account::withdraw(double amount){
    if (amount <= balance){
        balance -=  amount;
        std::cout<<"You withdrew $" << amount << ". Your balance is now: $" << balance <<"\n";
        std::shared_ptr<WithdrawTransaction> tx =  std::make_shared<WithdrawTransaction>(amount,accountNumber);
        addTransaction(tx);
    }
    else
        std::cout<<"You cannot withdraw more than your current balance: $ " << balance <<"\n";
}

//Display Details
void Account::displayDetails() const{
    std::cout<< "Account Number: " << accountNumber << "\n" 
             << "Owner: " << ownerName << "\n"
             << "Balance: " << balance << "\n";
}

//Getters
double Account::getBalance() const{
    return balance;
}
std::string Account::getOwnerName() const{
    return ownerName;
}
std::string Account::getAccountNumber() const{
    return accountNumber;
}

//Setters
void Account::setAccountNumber(const std::string &number){
    accountNumber = number;
}
void Account::setOwnerName(const std::string &name){
    ownerName = name;
}