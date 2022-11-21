/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E6.8
*/

/*
Write a function: bool equals(int a[], int a_size, int b[], int b_size) 
that checks whether two arrays have the same elements in the same order.
*/

#include <iostream>
#include <string>

bool equals(int a[], int a_size, int b[], int b_size){
    if(a_size != b_size){
        return false;
    }
    for(int i = 0; i < a_size; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}