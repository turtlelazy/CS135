/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: Project 3 Task 1
*/

#pragma once
#include <string>
class Account
{

private:
    std::string first_name;
    std::string last_name;
    std::string acc_number;
    std::string pin_number;
    int balance;
    std::string generateAccountNumber();

public:
    //set methods
    void setFirstName(std::string fname);
    void setLastName(std::string lname);
    bool setPin(std::string pin);

    //get methods
    std::string getFirstName();
    std::string getLastName();
    std::string getAccountNumber();
    std::string getPin();
    int getBalance();

    //transactions
    bool transaction(int amount);

    //constructors
    Account(std::string fname, std::string lname, std::string pin);
    Account();
};
