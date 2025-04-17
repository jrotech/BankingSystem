#pragma once
#include "Account.hpp"
#include <memory>
#include <unordered_map>

class Bank{
private:
    std::unordered_map<std::string, std::shared_ptr<Account>> accounts;

public:
    Bank();
    void addAccount();
    void getAccountByNumber(const std::string &accountNumber) const; 

};