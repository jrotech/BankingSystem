#include "Transaction.hpp"
#include <ctime>
#include <iostream>
//Static var
int Transaction::nextID = 1;

//Constructor
Transaction::Transaction(double amt, const std::string &accNum) : amount(amt), accountNumber(accNum), transactionID(nextID++), timestamp(std::time(nullptr)){
    std::cout << "Transaction " << transactionID << " created for account " << accountNumber << "\n";
}

//getType and display are virtual