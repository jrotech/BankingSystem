#include "Account.hpp"
#include <iostream>

int main(){
    Account Acc1("ABC1234","Sepiroth Johnson", 2000);
    Account* Acc2= new Account("MDI1234","Cloud Strifenson", 1500);

    Acc1.deposit(100);
    Acc1.withdraw(200);
    Acc1.displayDetails();
    Acc2->deposit(-100);
    Acc2->withdraw(3000);
    Acc2->displayDetails();

    delete Acc2;
    

}