// Function20_main_args.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <filesystem> //Since c++17
#include <cstdlib>

int main(int argc, char* argv[])
{
	constexpr int minimum_number_of_args = 2;
	if (argc < minimum_number_of_args) {
		std::cerr << "Invalid Syntax!\n";
		std::cerr << "to_trash <filename>[filenames..]";````````````````````````````````````````````````````````````````````````````````````````
			``````````````````````````````````````````````````````````````````````````````````````````````````````````````````
		exit(EXIT_FAILURE);
	}

	bool isDeleted;
	for (size_t idx = 1; idx < argc; ++idx) {
		std::filesystem::path path_to_delete = argv[idx];
		//std::cout << path_to_delete;
		isDeleted = std::filesystem::remove(path_to_delete);
		if (isDeleted) {
			std::cout << path_to_delete << " has been successfully deleted\n";
		}
		else {
			std::cout << path_to_delete << " hasnot been found\n";
		}
	}
	return EXIT_SUCCESS;
}
