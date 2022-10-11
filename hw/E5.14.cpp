/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E5.14
*/

/*
Write a function void sort2(int& a, int& b) that swaps the values of a and b, if a is greater than b and 
otherwise leaves a and b unchanged. For example: int u = 2;   int v = 3;   int w = 4;   int x = 1;   
sort2(u, v);
//u is still 2, v is still 3//   sort2(w, x);   //w is now 1, x is now 4//
*/


#include <iostream>
#include <string>

void sort2(int &a, int &b){
    if(a > b){
        int copy = a;
        a = b;
        b = copy;
    }
}

// int main(){
//     int a = 10;
//     int b = 5;

//     sort2(a,b);

//     std::cout << a << std::endl;
//     std::cout << b << std::endl;

//     return 0;
// }