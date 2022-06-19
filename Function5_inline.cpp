// Function5_inline.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

// compile with: /c
inline int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}


int main()
{
    std::cout << "Maximum of (3,4)   : " << max(3, 4) << std::endl;
    std::cout << "Some other operations\n";
    std::cout << "Maximum of (23,14) : " << max(23, 14) << std::endl;

    int a = 10;
    int b = 20;
    std::cout << "Maximum is :" << max(a++, b++) << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    return EXIT_SUCCESS;
}
