/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E4.8
*/

/*
Write a program that reads a word and prints each character of the word on a separate line. 
For example, if the user provides the input "Harry", the program prints:   H   a   r   r   y
*/

#include <iostream>
#include <string>
int main(){
    std::string s;

    std::cin >> s;
    for(int i = 0; i < s.length(); i++){
        std::cout << s[i] << "\n";
    }
    return 0;
}