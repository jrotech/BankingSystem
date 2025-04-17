#include "Account.hpp"
#include <iostream>
#include <memory>
#include "DepositTransaction.hpp"
#include "WithdrawTransaction.hpp"
#include "TransferTransaction.hpp"
#include "Bank.hpp"
#include <iomanip>

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
        std::cout<<"You ("<<getOwnerName()<<") deposited $" << amount << ". Your balance is now: $" << balance <<"\n";
        std::shared_ptr<DepositTransaction> tx =  std::make_shared<DepositTransaction>(amount,accountNumber);
        addTransaction(tx);
    }
    else
        std::cout<<"You ("<<getOwnerName()<<") cannot deposit a negative account\n";
}

//Withdraw
void Account::withdraw(double amount){
    if (amount <= balance){
        balance -=  amount;
        std::cout<<"You ("<<getOwnerName()<<") withdrew $" << amount << ". Your balance is now: $" << balance <<"\n";
        std::shared_ptr<WithdrawTransaction> tx =  std::make_shared<WithdrawTransaction>(amount,accountNumber);
        addTransaction(tx);
    }
    else
        std::cout<<"You ("<<getOwnerName()<<") cannot withdraw more than your current balance: $ " << balance <<"\n";
}
//Transfer
void Account::transfer(const std::shared_ptr<Bank>& bank, double amount, const std::string& toAccountNumber) {
    if (amount <= balance) {
        std::shared_ptr<Account> recipient = bank->getAccountByNumber(toAccountNumber);

        if (!recipient) {
            std::cout << "[Transfer Failed] No account found with number: " << toAccountNumber << "\n";
            return;
        }

        balance -= amount;
        recipient->deposit(amount);

        std::cout << "You ("<<getOwnerName()<<") transferred $" << std::fixed << std::setprecision(2) << amount
                  << " to account " << toAccountNumber << " belonging to " << recipient->getOwnerName()
                  << ".\nYour new balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";

        std::shared_ptr<TransferTransaction> tx = std::make_shared<TransferTransaction>(
            amount, accountNumber, toAccountNumber
        );
        addTransaction(tx);
    } else {
        std::cout << "[Transfer Failed] Insufficient balance.\n";
    }
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