#include "Bank.hpp"


void Bank::addAccount(const std::shared_ptr<Account> &account){
    accounts[account->getAccountNumber()] = account;
}

std::shared_ptr<Account> Bank::getAccountByNumber(const std::string &accountNumber) const{
    auto it = accounts.find(accountNumber);
    if (it != accounts.end())
        return it->second; //the value of the pair in the map
    return nullptr;
}

