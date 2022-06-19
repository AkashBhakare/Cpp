// Function_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Whwn an inline namespace is defined a using directive is implicitly inserted into its enclosing namespace.

#include <iostream>

namespace foo {
	void foo_func() {
		std::cout << "Inside foo::foo_func\n";
	}
}

inline namespace bar {
	void bar_func() {
		std::cout << "Inside bar::bar_func\n";
	}
}

int main()
{
	{
		//foo_func();
		/*When an inlinwe namespace is defined, a using directive is implicitly inserted into its enclosing namespace.*/

		bar_func();
		/*Whwn an inline namespace is defined, a using directive is implictly into its enclosing namespace.
		using namespace bar;
		*/

	}
	{
		foo::foo_func();
		//bar::bar_func();
	}
	{
		using namespace foo;
		foo_func();
		using namespace bar;
		bar_func();
	}
}