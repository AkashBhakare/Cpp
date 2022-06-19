// Arithmetic operator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    // Arithmetic operation on float type data
#include <iostream>
    float f1n = 10.0F;
    float f2n = 3.5F;

    std::cout << "float      : sizeof(3.1F): " << sizeof(3.1F) << " bytes" << std::endl;
    std::cout << "double     : sizeof(3.1) : " << sizeof(3.1) << " bytes" << std::endl;
    std::cout << "long double: sizeof(3.1L): " << sizeof(3.1L) << " bytes" << std::endl;
    // Addition
    float fadd = f1n + f2n;
    std::cout << f1n << " + " << f2n << " = " << fadd << std::endl;

    //minus
    std::cout << f1n << " - " << f2n << " = " << (f1n - f2n) << std::endl;

    //multiply
    std::cout << f1n << " * " << f2n << " = " << (f1n * f2n) << std::endl;

    //divide
    std::cout << f1n << " / " << f2n << " = " << (f1n / f2n) << std::endl;

    //modulus
    f1n = 7.0f;
    f2n = 3.0F;
    
    /*
     Error : Mod operator cannot operate on floating point values
     std::cout << f1n << " % " << f2n << " = " << (f1n % f2n) << std::endl;
     std::cout <<  (10.3 % 4.5)   << std::endl; 
     std::cout <<  (10.3L % 4.5L) << std::endl;
     */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
