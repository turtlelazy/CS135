/*
Author: Ishraq Mahid
Course : CSCI-135
Instructor: Proffesor Genady Maryash
Assignment: Project 2 Task 2
*/

#include <iostream>
#include <fstream>
#include <sstream>
std::string output_string(std::ifstream& read_file, int char_count);
std::string split_line(std::string line, int line_width);
std::string justify(std::string text, std::string headers, std::string body, int char_count);
bool uppercase(std::string line);

bool is_justify(std::string input){
    return input == "right" || input == "center" || input == "left";
}

int main(){
    //input file init
    std::string filename;
    std::cout << "Enter the input filename: ";
    std::cin >> filename;
    std::ifstream endfile;
    endfile.open(filename);

    std::string first_line;
    std::getline(endfile, first_line);

    int index = first_line.find(';');
    int char_count = (int) std::stoi(first_line.substr(0,index));
    first_line = first_line.substr(index+1);
    index = first_line.find(';');


    std::string body_justify = first_line.substr(0, index);
    std::string title_justify;
    std::string output_filename;

    if(is_justify(body_justify)){
        first_line = first_line.substr(index + 1);
        index = first_line.find(';');

        title_justify = first_line.substr(0, index);
        if(is_justify(title_justify)){
            first_line = first_line.substr(index + 1);
            index = first_line.find(';');
             output_filename = first_line.substr(0, index);
        }
        else{
            output_filename = title_justify + "";
            title_justify = body_justify;
        }
        
    }
    else{
        output_filename = body_justify + "";
        body_justify = "left";
        title_justify = body_justify;

    }
        

    // std::cout << char_count << "\n";
    // std::cout << body_justify << "\n";
    // std::cout    << title_justify << "\n";
    // std::cout << output_filename << "\n";
    //std::string file_output = output_string(endfile, char_count);

    std::string file_output = justify(output_string(endfile, char_count),title_justify,body_justify,char_count);
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
        //if(current_line.size() <= char_count){ 
        if(current_line.size() == 0 || uppercase(current_line)){ 
            
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
}

std::string add_spaces(int i){
    std::string return_string;
    for(int x = 0; x < i; x++){
        return_string += " ";
    }

    return return_string;
}

bool uppercase(std::string line){
    for (int i = 0; i < line.length(); i++){
        if(std::islower(line[i])){
            return false;
        }
    }
    return true;
}

std::string justify_right(std::string line, int char_count){
    int missing = char_count - line.size() - 1 ;
    return add_spaces(missing) + line;
}

std::string justify_center(std::string line, int char_count)
{
    int missing = char_count - line.size() - 1;
    return add_spaces(missing/2) + line + add_spaces(missing/2);
}
std::string justify_left(std::string line, int char_count)
{
    int missing = char_count - line.size() - 1;
    return line + add_spaces(missing);
}

std::string justify_line(std::string line, std::string headers, std::string body, int char_count)
{
    if(line == ""){
        return line;
    }
    else if(uppercase(line)){
        if(headers == "center"){
            return justify_center(line,char_count);
        }
        else if (headers == "right")
        {
            return justify_right(line, char_count);
        }
        else if (headers == "left")
        {
            return justify_left(line, char_count);
        }
    }

    else{
        if (body == "center")
        {
            return justify_center(line, char_count);
        }
        else if (body == "right")
        {
            return justify_right(line, char_count);
        }
        else if (body == "left")
        {
            return justify_left(line, char_count);
        }
    }
    return line;
}

std::string justify(std::string text, std::string headers, std::string body, int char_count)
{
    std::string return_string = "";
    std::istringstream iss(text);

    std::string current_line = "";
    bool first = true;
    while(std::getline(iss,current_line,'\n')){
        if(first){
            first = false;

        }
        else{
            return_string += "\n";
            if(uppercase(current_line) && current_line != ""){
                //return_string += "\n";
            }
        }
        return_string += justify_line(current_line,headers,body,char_count);
        
    }
    return return_string;
}