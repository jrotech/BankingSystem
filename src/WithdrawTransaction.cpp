#include "WithdrawTransaction.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

//Constructor
WithdrawTransaction::WithdrawTransaction(double amt, const std::string &accNum) : Transaction(amt, accNum){}

std::string WithdrawTransaction::getType() const {
    return "Withdraw";
}
void WithdrawTransaction::display() const {
    std::time_t ts = getTimestamp();

    std::cout << "[Withdraw] "
    << "Transaction ID: " << getID() << "\n"
    << "Account: " << getAccountNumber() << "\n"
    << "Amount: $" << std::fixed << std::setprecision(2) << getAmount() << "\n"
    << "Date: " << std::ctime(&ts);
}