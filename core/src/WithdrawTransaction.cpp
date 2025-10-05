#include "WithdrawTransaction.hpp"

#include <fmt/chrono.h>
#include <iomanip>
#include <iostream>

// Constructor
WithdrawTransaction::WithdrawTransaction(double amt, const std::string& accNum) : Transaction(amt, accNum) {}

std::string WithdrawTransaction::getType() const { return "Withdraw"; }
void WithdrawTransaction::display() const {
    std::time_t ts = getTimestamp();
    std::tm local_tm = *std::localtime(&ts);
    std::cout << "[Withdraw] " << "Transaction ID: " << getID() << "\n"
              << "Account: " << getAccountNumber() << "\n"
              << "Amount: $" << std::fixed << std::setprecision(2) << getAmount() << "\n"
              << "Date: " << fmt::format("{:%Y-%m-%d %H:%M:%S}", local_tm) << "\n";
}