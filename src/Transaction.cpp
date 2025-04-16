#include "Transaction.hpp"
#include <ctime>
#include <iostream>

//Static Variable
int Transaction::nextID = 1;

//Constructor
Transaction::Transaction(double amt, const std::string &accNum) : amount(amt), accountNumber(accNum), transactionID(nextID++), timestamp(std::time(nullptr)){
    std::cout << "Transaction " << transactionID << " created for account " << accountNumber << "\n";
}

//Getters
int Transaction::getID() const {
    return transactionID;
}

double Transaction::getAmount() const {
    return amount;
}

std::time_t Transaction::getTimestamp() const {
    return timestamp;
}

std::string Transaction::getAccountNumber() const {
    return accountNumber;
}