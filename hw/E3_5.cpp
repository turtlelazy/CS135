/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E3.5
*/

/*
Task: Write a program that reads three numbers and prints 'increasing' 
if they are in increasing order, 'decreasing' if they are in decreasing order, 
and 'neither' otherwise. Here, 'increasing' means 'strictly increasing', with 
each value larger than its predecessor. The sequence 3 4 4 would not be 
considered increasing.
*/

#include <iostream>
int main(){
    int one;
    int two;
    int three;

    std::cin >> one;
    std::cin >> two;
    std::cin >> three;

    if(one > two && two > three){
        std::cout << "decreasing\n";
    }
    else if(one < two && two < three){
        std::cout << "increasing\n";
    }
    else{
        std::cout << "neither\n";
    }
    return 0;
}