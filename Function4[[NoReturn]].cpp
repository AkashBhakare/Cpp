// Function4[[NoReturn]].cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
* A�function that specifies�[[noreturn]]�can prohibit returning by
* throwing an exception,
  entering an infinite loop, or
  calling another function designated with the [[noreturn]] attribute.
*/

#include <iostream>
#include <cstdlib>
#include <exception>

[[noreturn]] void f(int i);

int main()
{
    std::cout << "Hello World!\n";
    try {
        //f(10);
        f(-10);
    }
    catch (std::exception& err) {
        std::cerr << err.what() << std::endl;
    }

    return EXIT_SUCCESS;
}


[[noreturn]] void f(int i) {
    if (i > 0)
        throw std::exception("Received positive input");
    std::exit(EXIT_FAILURE);
}