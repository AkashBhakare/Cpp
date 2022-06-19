// File_IO_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <string_view>

void write_to_text_file(std::string_view file_name)
{
	std::ofstream output_file(file_name.data());
	if (!output_file.is_open()) {
		throw std::runtime_error("File could not be created\n");
	}
	/*using insertion operator to insert data into a text file*/
	output_file << "Anil Kappor" << '\n';
	output_file << 10 << '\n';
	/*flushes the stream and disassociate the stream from the file*/
	output_file.close();
	return;
}

void read_from_text_file(std::string_view file_name) {
	std::ifstream input_file(file_name.data());
	if (input_file.fail()) {
		throw std::runtime_error("File not found\n");
	}

	std::string name{};
	int roll{};
	/*Extract a string containing embedded spaces and assign to name*/
	std::getline(input_file, name);
	/*using extraction operator to extract the integer from the text file*/
	input_file >> roll;
	std::cout << name << "\n" << roll << "\n";
	input_file.close();
}

void read_and_write_multiple_characters(std::string_view filename) {

	// ofstream object not associated to any file
	std::ofstream out_file{};

	// Associating the the Stream object with the file
	out_file.open(filename.data());

	/*Operator ! has been overloaded to return the state of the fileobject*/
	if (!out_file) {
		throw std::runtime_error("Error creating file\n");
	}

	std::cout << "Please enter characters. Press Z to stop: \n";
	char ch{};
	do {
		// extract from keyboard(stdin) using extraction operator
		std::cin >> ch;
		// insert character into file stream (program defined) using insertion operator
		out_file << ch;
	} while (std::toupper(ch) != 'Z');

	// Flushes the the stream an disassociate it from the file
	out_file.close();

	/* construct ifstream object which is not associated with any file*/
	std::ifstream in_file{};

	/* ifstream object is associated with the file */
	in_file.open(filename.data());

	if (!in_file) {
		throw std::runtime_error("File not found for reading\n");
	}

	do {
		in_file >> ch; // reading from user defined stream object
		if (in_file) {
			std::cout << ch << ' '; // writing to predefined stream (stdout)
		}
	} while (!in_file.eof());// Returns true if the associated stream has reached end - of - file.

	/* Disassociate the stream object from the file*/
	in_file.close();
	std::cout.flush();
}


void  using_get_put_for_file_io(std::string_view filename) {
	std::ofstream outfile{};

	outfile.open(filename.data());

	if (!outfile.is_open()) {
		throw std::runtime_error("File could not be created\n");
	}

	std::cout << "Please enter characters. Press Z to stop: ";
	char ch{};
	do {
		// extract single character from keyboard(stdin) using get()
		ch = std::cin.get();    //  cin >> ch;

		// insert single character into file stream using put()
		outfile.put(ch);  //  outfile << ch;

	} while (std::toupper(ch) != 'Z');
	outfile.flush();
	outfile.close();

	std::ifstream infile(filename.data());
	if (!infile.is_open()) {
		throw std::runtime_error("file not found!\n");
	}

	do {
		//  extract data from file stream using get()
	   // ch = infile.get();
		infile.get(ch);//overloaded
		if (infile) {
			//insert data into ostream using put()
			std::cout.put(ch);   // cout << ch;
		}
	} while (!infile.eof());
	infile.close();

}

void  differentiate_get_getline() {
	constexpr size_t max_len{ 100 };
	char buffer[max_len];

	std::ifstream input_file("d:\\student.txt"); /* note the use of double slash \\  */
	if (input_file.fail()) { //checks if an error has occurred
		throw std::runtime_error("File not found\n");
	}

	size_t line{ 0 };
	do {
		//Cannot suppress the delimiting character
		//input_file.get(buffer, max_len);
		//input_file.get(buffer, max_len, '\n');
		//input_file.ignore(); //ignores the next characters; extract the character from stram
		//input_file.clear();

		//supresses the delimiting character
		//input_file.getline(buffer, max_len); //one Line
		//in.getline(arr, max_len, '\n'); //one line at time
		input_file.getline(buffer, max_len, ' '); //one word

		if (!input_file.fail()) {
			std::cout << buffer << std::endl;
			std::cout << ++line << '\n';
		}

	} while (!input_file.eof());
	input_file.close();
	std::cout << "Line Count : " << line << std::endl;
}

int main()
{
	try {
		std::string filename{ "d:/student.txt" };
		//write_to_text_file(filename);
		//read_from_text_file(filename);
		//read_and_write_multiple_characters(filename);
		//using_get_put_for_file_io(filename);
		//differentiate_get_getline();
	}
	catch (std::exception& err) {
		std::cerr << err.what();
	}
}