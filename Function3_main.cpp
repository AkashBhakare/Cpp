// Function3_main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <stdexcept>

void foo(int x) {
	std::cout << "Entered foo\n";
	if (x <= 0) {
		std::cout << "Error has occured in foo\n";
		throw std::out_of_range("Zero is not allowed\n");
	}
	std::cout << "Successfully retruning from foo\n";
	return;
}



int main(void) {
	std::cout << "Doing something in main!\n";
	try {
		std::cout << "Calling foo from main\n";
		foo(10);
	}
	catch (std::out_of_range& err) {
		std::cout << "Inside catch..\n";
		std::cout << err.what();
		return EXIT_FAILURE;
	}
	std::cout << "Returning from main():\n";
	return EXIT_SUCCESS;
}

//Unix : echo $?

/*
Windows:

@echo off
@if "%ERRORLEVEL%" == "0" goto good
:fail
	echo Execution Failed
	echo return value = %ERRORLEVEL%
	goto end
:good
	echo Execution Succeeded
	echo return value = %ERRORLEVEL%
	goto end
:end*/
