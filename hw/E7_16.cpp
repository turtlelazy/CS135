/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E7.16
*/

/*
Define a structure Point. A point has an x- and a y-coordinate. Write a function double 
distance(Point a, Point b) that computes the distance from a to b. Write a program that 
reads the coordinates of the points, calls your function, and displays the result.
*/
#include <cmath>
#include <iostream>

class Point
{
public:
    double x;
    double y;
};

double distance(Point a, Point b){
    return sqrt( pow(a.x - b.x,2) + pow(a.y - b.y,2) );
}

int main(){
    double x1,y1,x2,y2;
    std::cout << "Point x1\n";
    std::cin >> x1;
    std::cout << "Point y1\n";
    std::cin >> y1;

    std::cout << "Point x2\n";
    std::cin >> x2;
    std::cout << "Point y2\n";
    std::cin >> y2;

    Point a = {x1,y1};
    Point b = {x2,y2};
    std::cout << "Distance is: " << distance(a,b) << "\n";
    return 0;
}