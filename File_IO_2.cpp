// File_IO_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Reading and writing student records

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "Student.h"
using namespace std::literals;

void write_student_records_csv(std::string_view filename, size_t number_of_records) {

	std::ofstream ofile{ filename.data() };
	if (not ofile) {
		throw std::runtime_error("File couldnt be created for writing\n");
	}
	char cname[100];
	std::string name{};
	float percentage{};
	int rollno{};

	for (size_t idx{ 1 }; idx <= number_of_records; ++idx) {
		std::cout << "Enter Details of student number " << idx << '\n';
		std::cout << "Name : ";
		// std::cin.getline(cname,std::numeric_limits<std::streamsize>::max(),'\n');
		std::getline(std::cin, name);

		std::cout << "Roll Number : ";
		std::cin >> rollno;

		std::cout << "Percentage : ";
		std::cin >> percentage;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		ofile << name << ',';
		ofile << rollno << ',';
		ofile << percentage << '\n';
		ofile.flush();
	}
	ofile.close();
}

void read_student_records_csv(std::string_view filename) {
	std::ifstream ifile{ filename.data() };
	if (not ifile) {
		throw std::runtime_error("File not found for reading\n");
	}

	char name[100];
	float percentage{};
	int rollno{};

	do {
		ifile.getline(name, std::numeric_limits<std::streamsize>::max(), ',');
		if (ifile.eof()) {
			break;
		}
		// ifile.ignore(std::numeric_limits<std::streamsize>::max(), ',');
		ifile >> rollno;
		ifile.ignore(std::numeric_limits<std::streamsize>::max(), ',');
		ifile >> percentage;
		ifile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Name : " << name << "\n";
		std::cout << "Roll Number : " << rollno << "\n";
		std::cout << "Percentage  :" << percentage << "\n\n";

	} while (true);
	ifile.close();
}

void working_with_text_files() {
	std::string_view filename{ "d:\\student.csv" };
	size_t number_of_records{ 2 };
	/*Working with text file*/
	try {
		write_student_records_csv(filename, number_of_records);
		read_student_records_csv(filename);
	}
	catch (std::exception& err) {
		std::cerr << err.what();
	}
}

void write_student_records_binary(std::string_view filename, size_t number_of_records) {


	std::ofstream ofile{};
	ofile.open(filename.data(), std::ios::binary | std::ios::out | std::ios::app);
	if (ofile.fail()) {
		throw std::runtime_error("File couldnt be created for writing\n");
	}

	mylib::Student student{};
	for (size_t idx{ 1 }; idx <= number_of_records; ++idx) {
		//Extract Student data from stdin
		std::cin >> student;
		ofile << student;
		//Following statement will work but its better if you use the overloaded operator
		// ofile.write(reinterpret_cast<const char*>(&student),sizeof(student));
		//Insert Student in stdout
		//std::cout << student;
	}
	//Insert Student Record into the file  
	ofile.close();


}

void read_student_records_binary(std::string_view filename) {
	std::ifstream ifile{};
	ifile.open(filename.data(), std::ios::binary | std::ios::in);
	if (ifile.fail()) {
		throw std::runtime_error("File couldnt be opened for reading\n");
	}

	mylib::Student student{};
	do {
		ifile >> student;
		/*
		Following statement will work but prefer overloaded operator
		ifile.read(reinterpret_cast<char*>(&student), sizeof(student));
		*/
		if (ifile.fail() || ifile.eof()) {
			break;
		}
		std::cout << student << '\n';
	} while (true);
	ifile.close();
}

void modify_record(std::string_view filename) {
	std::fstream iofile{};
	iofile.open(filename.data(), std::ios::binary | std::ios::in | std::ios::out | std::ios::ate);
	if (iofile.fail()) {
		throw std::runtime_error("File couldnt be opened for modification\n");
	}
	std::cout << "Please enter the record number to modify : ";
	size_t record_number{};
	std::cin >> record_number;
	std::cout << "Current Position : " << iofile.tellg() << '\n';
	std::streampos seek_position = static_cast<std::streampos>(sizeof(mylib::Student)) * (record_number - 1);
	iofile.seekg(seek_position, std::ios::beg);
	std::cout << "New Position : " << iofile.tellg() << '\n';
	mylib::Student student{};
	iofile >> student;
	std::cout << "The following student record will now be modified : \n";
	std::cout << student << '\n';
	std::cout << "Please enter the updated details for the same student :\n";
	std::cin >> student;
	iofile.seekp(seek_position, std::ios::beg);
	iofile << student;
	iofile.close();
}

void  working_with_binary_files() {
	/*working with binary files*/
	std::string filename = "d:\\student.dat";
	size_t number_of_records{ 3 };
	try {
		// write_student_records_binary(filename, number_of_records);
		read_student_records_binary(filename);
		modify_record(filename);
		read_student_records_binary(filename);
	}
	catch (std::exception& err) {
		std::cerr << err.what();
	}
}


int main()
{
	// working_with_text_files();
	working_with_binary_files();


}