/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E5.15
*/

/*
Write a function sort3(int& a, int& b, int& c) that swaps its three arguments to arrange 
them in sorted order. For example: int v = 3;   
int w = 4;   
int x = 1;   
sort3(v, w, x);  //v is now 1, w is now 3, x is now 4//   
Hint: Use multiple calls to the sort2 function of Exercise E5.14.
*/

#include <iostream>
#include <string>

void sort2(int &a, int &b)
{
    if (a > b)
    {
        int copy = a;
        a = b;
        b = copy;
    }
}

void sort3(int &a, int &b, int &c){
    sort2(a,b);
    sort2(a,c);
    sort2(b,c);
}

// int main(){
//     int a = 10;
//     int b = 21;
//     int c = 14;

//     sort3(a,b,c);

//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << c << std::endl;

//     return 0;
// }