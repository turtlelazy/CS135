#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

int main()
{
    std::cout << "Enter the input filename: ";
    std::string input_file;
    std::cin >> input_file;

    std::ifstream in_file(input_file);
    int width = 0;
    in_file >> width;

    std::string junk;
    in_file >> junk;
    std::string output;
    output = junk.substr(1, junk.length() - 2);
    std::ofstream out_file(output);
    int count = 0;
    int index_space;
    getline(in_file, junk);
    bool newLine = false;

    while (std::getline(in_file, input_file))
    {
        if (input_file.length() == 0)
        {
            newLine = true;
        }

        if (newLine)
        {
            out_file << std::endl;
            count = 0;
            newLine = false;
        }

        if (count + input_file.length() < width)
        {
            if (count > 0)
                out_file << " " << input_file;
            else
                out_file << input_file;
            count = count + input_file.length();
            if (in_file.eof() == false)
            {
                newLine = true;
            }
        }

        else
        {
            //Finding when is the last space before it reaches the max width (taking into account the current width)
            while (input_file.length() > width - count)
            {
                if (input_file.substr(0, input_file.find(' ') - 1).length() + count > width)
                {
                    out_file << std::endl;
                    count = 0;
                }

                for (int x = 0; x < input_file.length(); x++)
                {
                    if (input_file[x] == ' ' && x < width - count)
                    {
                        index_space = x;
                    }
                }

                //If there are words beforehand, have print a space first.
                if (count > 0)
                {
                    out_file << " " << input_file.substr(0, index_space);
                }
                else
                {
                    out_file << input_file.substr(0, index_space);
                }
                out_file << std::endl;
                count = 0;
                //Resetting the count because we are in a new line
                input_file = input_file.substr(index_space);
                if (input_file[0] == ' ')
                {
                    input_file = input_file.substr(1);
                }
            }

            if (input_file[input_file.length() - 1] == ' ')
            {
                input_file = input_file.substr(0, input_file.length() - 1);
            }

            out_file << input_file;
            count = input_file.length();
        }
    }
    return 0;
}
