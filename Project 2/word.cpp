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
    //std::cout << char_count << "\n"; 
    //std::cout << output_filename << std::endl;

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
    bool printed = false;
    bool line_break = false;

    std::string current_paragraph = "";
    while (std::getline(read_file, current_line))
    {
        current_paragraph += " " + current_line;
        if(current_line.size() <= char_count){ 
            // else{
            printed = true;
            return_string += split_line(current_paragraph, char_count);
            // }
            if (current_line == "" && return_string[return_string.size()-1] != '\n')
            {
                return_string += "\n";
            }
            return_string += "\n";
            current_paragraph = "";
        }
        else{
            printed = false;
        }

    }
    if (!printed)
    {
        return_string += split_line(current_paragraph, char_count);
    }
    if(return_string[return_string.size()-1] == '\n'){
        return return_string.substr(0,return_string.size()-1);
    }
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