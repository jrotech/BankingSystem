#include "DepositTransaction.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

//Constructor
DepositTransaction::DepositTransaction(double amt, const std::string &accNum) : Transaction(amt, accNum){}

std::string DepositTransaction::getType() const {
    return "Deposit";
}
void DepositTransaction::display() const {
    std::time_t ts = getTimestamp();

    std::cout << "[Deposit] "
    << "Transaction ID: " << getID() << "\n"
    << "Account: " << getAccountNumber() << "\n"
    << "Amount: $" << std::fixed << std::setprecision(2) << getAmount() << "\n"
    << "Date: " << std::ctime(&ts);
}