/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: Project 2 Task 1
*/

#include <iostream>
#include <fstream>
#include <sstream>
std::string output_string(std::ifstream& read_file, int char_count);
std::string split_line(std::string line, int line_width);

int main(){

    //input file init
    std::string filename;
    std::cout << "Enter the input filename: ";
    std::cin >> filename;
    std::ifstream endfile;
    endfile.open(filename);

    //first line info
    std::string first_line;
    std::getline(endfile, first_line);
    int index = first_line.find(';');
    int char_count = (int) std::stoi(first_line.substr(0,index));
    std::string output_filename = first_line.substr(index+1,first_line.size()-index-2);
    std::cout << char_count << "\n"; 
    std::cout << output_filename << std::endl;

    //processing
    //std::cout << output_string(endfile,char_count);
    std::string file_output = output_string(endfile, char_count);
    //close input file
    endfile.close();


    std::ofstream outfile;
    outfile.open(output_filename);
    outfile << file_output;
    outfile.close();

    return 0;
}

std::string output_string(std::ifstream& read_file, int char_count){
    std::string return_string = "";
    std::string current_line;
    bool first = true;
    while (std::getline(read_file, current_line))
    {
        if(!first){
            return_string += "\n";
        }
        else{
            first = false;
        }

        //std::getline(read_file, current_line);
        // if(current_line == ""){
        //     return_string += "\n";
        // }
        // else{
            return_string += split_line(current_line,char_count);
        //}
    }

    // char s;
    // read_file >> std::noskipws;
    // char last_char = ' ';

    // int line_count = 0;
    // while(read_file >> s){
    //     if(s == '\n'){
    //         if(last_char == '\n'){
    //             return_string+= "\n\n" ;
    //             line_count = 0;
    //         }
    //     }
    //     else{
    //         if(line_count < char_count){
    //             return_string += s;
    //         }
    //         else{
    //             return_string += '\n' + s;
    //             char_count = 0;
    //         }
    //         char_count += 1;
    //     }

    //     last_char = s;
    // }

    return return_string;
}

std::string split_line(std::string line, int line_width){
    std::string return_string  = "";
    int char_count = 0;
    std::istringstream iss(line);
    std::string word;
    bool first = true;
    while(iss >> word){
        int size = word.length() + 1;
        if (first)
        {
            return_string += word;
            char_count += word.size();
            first = false;
        }
        else{

            if (size + char_count < line_width)
            {
                return_string += " " + word;
                char_count += size;
            }

            else
            {
                return_string += "\n" + word;
                char_count = word.size();
            }
        }
    }
    
    return return_string;

    //return line;
}

std::string add_spaces(int i){
    std::string return_string;
    for(int x = 0; x < i; x++){
        return_string += " ";
    }

    return return_string;
}