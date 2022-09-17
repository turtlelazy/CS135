#include <iostream>
#include <string>

int maze[6][6] = {
    1, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 1,
    1, 0, 1, 0, 0, 1,
    1, 0, 1, 0, 1, 1,
    1, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1
    };

int main(){
    int pX = 1;
    int pY = 0;

    int Fx = 1;
    int Fy = 0;

    std::string instructions;
    std::cin >> instructions;

    instructions = cleanInput(instructions);

    return 0;
}

std::string cleanInput(std::string input){
    int N = input.length();
    std::string newOutput = "";
    for(int i = 0; i < N; i++){
        if(input[i] != ' '){
            newOutput += input[i];
        }
    }
    return newOutput;
}

int endX(int startX, std::string cleanedInput){
    for(int i = 0; i < cleanedInput.length();i++){
        
    }
}