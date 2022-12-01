#include <iostream>
#include "Account.hpp"

int main(){
    Account acc;
    Account account("John","Dewey","1234");

    std::cout << "get acc number" << acc.getAccountNumber() << "\n";
    std::cout << "get name" << acc.getFirstName() << "\n";
    std::cout << "get pin" << account.getPin() << "\n";
    account.transaction(100);
    account.transaction(-200);

    std::cout << "get balance" << account.getBalance() << "\n";

    return 0;
}