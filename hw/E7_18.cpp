/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: HW E7.16
*/

/*
Define a structure Triangle that contains three Point members. 
Write a function that computes the `perimeter()` of a Triangle. 
Write a program that reads the coordinates of the points, calls your function, 
and displays the result.*/
#include <cmath>
#include <iostream>

class Point
{
public:
    double x;
    double y;
};

class Triangle
{
public:
    Point p1;
    Point p2;
    Point p3;
};

double distance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double perimeter(Triangle t){
    double d1 = distance(t.p1, t.p2);
    double d2 = distance(t.p2, t.p3);
    double d3 = distance(t.p3, t.p1);

    return d1 + d2 + d3;
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    std::cout << "Point x1\n";
    std::cin >> x1;
    std::cout << "Point y1\n";
    std::cin >> y1;

    std::cout << "Point x2\n";
    std::cin >> x2;
    std::cout << "Point y2\n";
    std::cin >> y2;

    std::cout << "Point x3\n";
    std::cin >> x3;
    std::cout << "Point y3\n";
    std::cin >> y3;

    Point a = {x1, y1};
    Point b = {x2, y2};
    Point c = {x3, y3};
    Triangle triangles = {a,b,c};
    std::cout << "Perimeter is: " << perimeter(triangles) << "\n";
    return 0;
}