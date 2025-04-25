#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>
#include <memory>

int main() {
    // Create a bank instance
    auto bank = std::make_shared<Bank>();

    // Create some accounts
    auto acc1 = std::make_shared<Account>("ACC001", "Bruce Wayne", 100000.0);
    auto acc2 = std::make_shared<Account>("ACC002", "Clark Kent", 500.0, 0.05); // higher interest rate
    auto acc3 = std::make_shared<Account>("ACC003", "Diana Prince", 2000.0);

    // Add accounts to the bank
    bank->addAccount(acc1);
    bank->addAccount(acc2);
    bank->addAccount(acc3);

    std::cout << "\n=== Initial Balances ===\n";
    acc1->displayDetails();
    acc2->displayDetails();
    acc3->displayDetails();

    // Perform deposits
    acc1->deposit(250);
    acc2->deposit(100);
    acc3->deposit(0);  // edge case: zero deposit

    // Perform withdrawals
    acc1->withdraw(100);
    acc2->withdraw(600);  // should fail: overdraft
    acc3->withdraw(500);

    // Apply interest
    acc1->applyInterest();
    acc2->applyInterest();
    acc3->applyInterest();

    // Transfer money
    acc1->transfer(bank, 200, "ACC002");  // valid
    acc2->transfer(bank, 1000, "ACC003"); // should fail
    acc3->transfer(bank, 300, "ACC004");  // should fail (no such account)

    std::cout << "\n=== Final Balances ===\n";
    acc1->displayDetails();
    acc2->displayDetails();
    acc3->displayDetails();

    std::cout << "\n=== Test Complete ===\n";
    return 0;
}
