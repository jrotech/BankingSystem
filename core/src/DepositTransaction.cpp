#include "DepositTransaction.hpp"

#include <fmt/chrono.h>
#include <iomanip>
#include <iostream>

// Constructor
DepositTransaction::DepositTransaction(double amt, const std::string& accNum) : Transaction(amt, accNum) {}

std::string DepositTransaction::getType() const { return "Deposit"; }
void DepositTransaction::display() const {
    std::time_t ts = getTimestamp();
    std::tm local_tm = *std::localtime(&ts);
    std::cout << "[Deposit] " << "Transaction ID: " << getID() << "\n"
              << "Account: " << getAccountNumber() << "\n"
              << "Amount: $" << std::fixed << std::setprecision(2) << getAmount() << "\n"
              << "Date: " << fmt::format("{:%Y-%m-%d %H:%M:%S}", local_tm) << "\n";
}