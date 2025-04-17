#pragma once
#include "Account.hpp"
#include <memory>
#include <unordered_map>

class Bank{
private:
    std::unordered_map<std::string, std::shared_ptr<Account>> accounts;

public:
    Bank();
    void addAccount(const std::shared_ptr<Account> &account);
    std::shared_ptr<Account> getAccountByNumber(const std::string &accountNumber) const; 

};