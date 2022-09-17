/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Genady Maryash
Assignment: HW E2.10
*/

#include <iostream>
#include <string>

int main(){
    float gal;
    float mpg;
    float price;

    std::cout << "Gallons?" << std::endl;
    std::cin >> gal;

    std::cout << "Mpg?" << std::endl;
    std::cin >> mpg;

    std::cout << "Price?" << std::endl;
    std::cin >> price;

    std::cout << 100.0 / mpg * price  << std::endl;
    std::cout << gal * mpg << std::endl;


}