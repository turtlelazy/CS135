#include <iostream>
#include <string>

void direction(char letter);
int main()
{
    char s;
    while (std::cin >> s)
    {                      // While the reading operation is a success
        direction(s); // print the read word
    }
    return 0;
}

void direction(char letter){
    if(letter != ' '){
        if(letter == 'R'){
            std::cout << "Right\n";
        }
        else if (letter == 'L')
        {
            std::cout << "Left\n";
        }

        else if (letter == 'U')
        {
            std::cout << "Up\n";
        }

        else if (letter == 'D')
        {
            std::cout << "Down\n";
        }
    }
}