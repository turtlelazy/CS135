/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E8.1
*/

/*
Write a program that carries out the following tasks:  Open a file with the name hello.txt.
Store the message “Hello, World!” in the file. Close the file.  Open the same file again.  
Read the message into a string variable and print it.
*/

#include <iostream>
#include <fstream>

int main(){
    std::ofstream outfile;
    outfile.open("hello.txt");
    outfile << "Hello, World!";
    outfile.close();

    std::ifstream endfile;
    endfile.open("hello.txt");
    std::string str;
    std::getline(endfile,str);
    std::cout << str;
    endfile.close();

    return 0;
}
