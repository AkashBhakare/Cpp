// File_IO_5.cpp : In memory operations

#include <iostream>
#include <sstream>
#include <stdexcept>

void read_from_memory() {
    std::istringstream input_src("ABCDEFGHIJKLMNOPQRSTUVWXYZ",std::ios::in);
    
    std::cout << "Initial Position of get pointer : " << input_src.tellg() << '\n';
    std::cout << "Reading one charater at a time from memory :\n";
    char ch{};
    input_src.exceptions(std::ios::failbit);
    try {
        do {
            std::cout << "Position = " << input_src.tellg();
            ch = input_src.get();
            if (not input_src.fail()) {
                std::cout << "\t Charater = " << ch << "\n";
            }

        } while (not input_src.eof());
        std::cout << '\n';
    }
    catch (std::bad_exception& e) {
        std::cerr << e.what() << '\n';
    }
    //std::Cout << "State of the src : " << input_src.rdstate() << '\n';
    std::cout << '\n';

    std::cout << "Repositioning the get pointer to begining to read alternate charater : \n";
    input_src.clear(); //clear the failbit flag

    input_src.seekg(0,std::ios::beg);
    do {
        std::cout << "Position = " << input_src.tellg();
        ch = input_src.get();
        if (not input_src.fail()) {
            std::cout << "\t Charater = " << ch << "\n";
            input_src.ignore(1);
        }

    } while (not input_src.eof());
    input_src.clear();
}

void read_and_update_memory() {
    std::istringstream input_src("ABCDEFGHIJKLMNOPQRSTUVWXYZ", std::ios::in | std::ios::ate);
    std::cout << "Reading the entire content at one go  : \n";
    //gets the contents of underlying string device object
    std::cout << input_src.str() << '\n';
    //sets the contents of underlying string device object
    input_src.str("123456789");
    std::cout << "Reading updated entire content at one go : \n";
    std::cout << input_src.str();
}

void  writing_data_to_memory() {
    std::ostringstream dest("ABCDEFGHIJKLMNOPQRSTUVWXYZ", std::ios::out);
    std::cout << "Reading Original entire content at one go  : \n";
    std::cout << dest.str() << '\n';
    dest.str("");
    dest << "first\n";
    dest << 12345 << '\n';
    dest << 12.999 << '\n';
    dest << std::hex << std::showbase << 65535 << '\n';
    std::cout << "Reading updated entire content at one go : \n";
    std::cout << dest.str() << '\n';
    dest.seekp(std::ios::beg, 7);
    dest << "Hello\n";
    std::cout << "Reading updated entire content at one go : \n";
    std::cout << dest.str() << '\n';
}

int main()
{
    //read_from_memory();
    //read_and_update_memory();
    writing_data_to_memory();
}
