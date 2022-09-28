/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Professor Genady Maryash
Assignment: Project Task 3
*/

#include <iostream>
#include <string>

int endY(int startY, char letter);
int endX(int startX, char letter);
bool success(int goalX, int pX, int goalY, int pY);
bool valid(int pX, int pY, int maze[6][6]);

int maze[6][6] = {
    1, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 1,
    1, 0, 1, 0, 0, 1,
    1, 0, 1, 0, 1, 1,
    1, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1};

int main()
{
    int pX = 1;
    int pY = 0;

    int goalX = 5;
    int goalY = 4;
    char s;
    while (std::cin >> s)
    { // While the reading operation is a success
        //direction(s); // print the read word

        if(s == ';'){
            if(success(goalX, pX, goalY, pY)){
                pX = 1;
                pY = 0;
            }

            continue;
        }

        if (valid(endX(pX, s), endY(pY, s), maze))
        {
            pX = endX(pX, s);
            pY = endY(pY, s);
        }

        // if(!valid(pX,pY,maze)){
        //     std::cout << "You are stuck in the maze.\n";
        //     std::cout << pX << "X\n";
        //     std::cout << pY << "Y\n";
        //     return 0;
        // }
    }
    // std::cout << goalX << " " << pX << "\n";
    // std::cout << goalY << " " << pY << "\n";

    return 0;
}

int endX(int startX, char letter)
{
    if (letter != ' ')
    {
        if (letter == 'R')
        {
            startX += 1;
        }
        else if (letter == 'L')
        {
            startX -= 1;
        }
    }
    return startX;
}

int endY(int startY, char letter)
{
    if (letter != ' ')
    {
        if (letter == 'D')
        {
            startY += 1;
        }
        else if (letter == 'U')
        {
            startY -= 1;
        }
    }
    return startY;
}

bool success(int goalX, int pX, int goalY, int pY)
{
    if (goalX == pX && goalY == pY)
    {
        std::cout << "You got out of the maze.\n";
        return true;
    }
    else
    {
        std::cout << "You are stuck in the maze.\n";
        return false;

        // std::cout << pX << "X\n";
        // std::cout<< pY << "Y\n";
    }
}

bool valid(int pX, int pY, int maze[6][6])
{
    return maze[pY][pX] == 0;
}