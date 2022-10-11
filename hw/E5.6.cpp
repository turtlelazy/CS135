/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E5.6
*/

/*
Write a function string middle(string str) that returns a string containing 
the middle character in   str   if the length of str is odd, or the two middle 
characters if the length is even. For example, middle('middle') returns 'dd'.
*/

#include <iostream>
#include <string>


std::string middle(std::string str){
    
    if(str.length() % 2 == 0){
        std::string c3 = str[str.length() / 2 - 1] + std::string(1, str[str.length() / 2]);
        return c3;
    }

    return std::string(1, str[str.length() / 2]);
}