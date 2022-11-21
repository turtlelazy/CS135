/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E7.1
*/

/*
Write a function void sort2(double* p, double* q) that receives two pointers and sorts the 
values to which they point. If you call sort2(&x, &y) then x <= y after the call.
*/
#include <iostream>
#include <fstream>

void sort2(double *p, double *q);

// int main()
// {   
//     double a = 10;
//     double b = 20;
//     double *p = &a;
//     double *q = &b;

//     std::cout << *p << " " << *q << "\n";
//     sort2(p,q);
//     std::cout << *p << " " << *q << "\n";

//     return 0;
// }

void sort2(double *p, double *q){
    if(*p > *q){
        double copy_q = *q;
        double copy_p = *p;

        *p = copy_q;
        *q = copy_p;
    }
}

// void sort2(int &a, int &b)
// {
//     if (a > b)
//     {
//         int copy = a;
//         a = b;
//         b = copy;
//     }
// }