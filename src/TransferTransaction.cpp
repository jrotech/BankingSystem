#include "TransferTransaction.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

TransferTransaction::TransferTransaction(double amt, const std::string &accNum, const std::string &toAccNum) :
    Transaction(amt, accNum) , toAccountNumber(toAccNum) {}

std::string TransferTransaction::getType() const{
    return "Transfer";
}
std::string TransferTransaction::getToAccountNumber() const{
    return toAccountNumber;
}
void TransferTransaction::display() const{
    std::time_t ts = getTimestamp();

    std::cout << "[Transfer] "
    << "Transaction ID: " << getID() << "\n"
    << "From Account: " << getAccountNumber() << "\n"
    << "To Account: " << getToAccountNumber() << "\n"
    << "Amount: $" << std::fixed << std::setprecision(2) << getAmount() << "\n"
    << "Date: " << std::ctime(&ts);
}

