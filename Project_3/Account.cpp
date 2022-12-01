/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: Project 3 Task 1
*/

#include <iostream>
#include "Account.hpp"
#include <cctype>

std::string Account::generateAccountNumber()
{
    std::string an_str = "";
    for (int i = 0; i < 8; i++)
    {
        int temp = std::rand() % 10;
        an_str += std::to_string(temp);
    }
    return an_str;
}

Account::Account(){
    first_name = "anonymous";
    last_name = "anonymous";
    pin_number = "0000";
    acc_number = generateAccountNumber();
    balance = 0;
}

Account::Account(std::string fname, std::string lname, std::string pin){
    first_name = fname;
    last_name = lname;
    setPin(pin);
    acc_number = generateAccountNumber();
    balance = 0;
}

void Account::setFirstName(std::string fname){
    first_name = fname;
}

void Account::setLastName(std::string lname)
{
    last_name = lname;
}

bool Account::setPin(std::string pin){
    if(pin.length() == 4){
        for(int i = 0; i < pin.length();i++){
            if (!std::isdigit(pin[i])){
                pin_number = "0000";
                return false;
            }
        }
    }
    pin_number = pin;
    return true;
}

std::string Account::getFirstName(){
    return first_name;
}

std::string Account::getLastName(){
    return last_name;
}

std::string Account::getAccountNumber(){
    return acc_number;
}

std::string Account::getPin(){
    return pin_number;
}

int Account::getBalance(){
    return balance;
}

bool Account::transaction(int amount){
    if(balance + amount < 0){
        return false;
    }
    balance += amount;
    return true;
}
