// Function7_inlineVsMacro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include <iostream>


//inline function
inline char f_toupper(char a) {
	return ((a >= 'a' && a <= 'z') ? a - ('a' - 'A') : a);
}

//Macro
#define m_toupper(a) ((a) >= 'a' && ((a) <= 'z') ? ((a)-('a'-'A')):(a))

int main() {
	char ch;
	std::cout << "Enter a character: ";
	//ch = m_toupper(getc(stdin));
	ch = f_toupper(getc(stdin));
	std::cout << "Character is :" << ch << std::endl;
	return 0;
}

/*
The intent of the expression toupper(getc(stdin)) is that a character
should be read from the console device (stdin) and, if necessary, converted
to uppercase.

Because of the implementation of the macro, getc is executed once to
determine whether the character is greater than or equal to "a," and
once to determine whether it's less than or equal to "z."
If it is in that range, getc is executed again to convert the character
to uppercase. It means the program waits for two or three characters when,
ideally, it should wait for only one.

Inline functions remedy the problem previously described

*/


