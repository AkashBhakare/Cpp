// compound assignment operator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

int main()
{
 /*   int i1n = 4;
    std::cout << i1n << std::endl;
    std::cout << i1n << std::endl;
 
    int i1n = 4;
    std::cout << i1n << std::endl;
    std::cout << i1n + 10 << std::endl;
    std::cout << i1n << std::endl;

    i1n = i1n + 10;
    std::cout << i1n << std::endl;
    i1n += 10; // i1n = i1n + 10;
    std::cout << i1n << std::endl;
    i1n /= 4;  // i1n = i1n / 4;
    std::cout << i1n << std::endl;
    i1n *= 5; // i1n = i1n * 5;
    std::cout << i1n << std::endl;


    //commma operator
    int a;
    int b;
    int c;
    int d;
    int e = 2;

    // a = 10;
    // b = 5;
    // c = 20;
    // d = a+b;

    d = (a = 10, b = 5, c = 20, a + b);

    // d = (a=10,b=5,c=20,30+3*e);

    std::cout << "a:" << a << "\tb:" << b << "\tc:" << c << "\td:" << d << std::endl;

    //Relational operator
    int a = 10;
    int b = 20;
    std::cout << "(a > b) ? " << (a > b) << std::endl;
    std::cout << "(a < b) ? " << (a < b) << std::endl;

    std::cout << "(a > b) ? " << std::setiosflags(std::ios::boolalpha) << (a > b) << std::endl;
    std::cout << "(a < b) ? " << std::setiosflags(std::ios::boolalpha) << (a < b) << std::endl;


    a = 10;
    b = 10;
    std::cout << "(a > b) ? " << (a > b) << std::endl;
*/

    int a = 10;
    int b = 20;
    int c = a > b;
    std::cout << "a:" << a << "\tb:" << b << "\tc:" << c << std::endl;
    c = a != b;
    std::cout << "a:" << a << "\tb:" << b << "\tc:" << c << std::endl;

    int result;
    result = a != b + a<b + a>b - a > c;
    std::cout << "a:" << a << "\tb:" << b << "\tc:" << c << "\tresult:" << result << std::endl;

    a = 10;
    b = 20;
    c = 2;
    result = a != (b + a) < (b + a) > (b - a) == c;
    // result = 10!=30<30>10==2;
    // result = 10!=(30<30)>10==2;
    // result = 10!=(0)>10==2;
    // result = 10!=0==2;
    // result = 1==2;
    std::cout << "a:" << a << "\tb:" << b << "\tc:" << c << "\tresult:" << result << std::endl;
    std::cout << "(a < b) ? " << (a < b) << std::endl;
    std::cout << "(a >= b) ? " << (a >= b) << std::endl;
    std::cout << "(a <= b) ? " << (a <= b) << std::endl;
    

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
