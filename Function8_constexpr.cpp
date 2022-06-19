// Function8_constexpr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

void f(int);

constexpr int sqr(int n)
{
    return n * n;
}

constexpr auto add(int a, int b)->int;

constexpr void f4(int x) {  // Error, return type should not be void.
    return;
}

int main()
{
    f(4);

    return EXIT_SUCCESS;
}


void f(int n)
{
    int f5 = sqr(5); // MAY be evaluated at compile time

    int fn = sqr(n); // evaluated at run time (n is a variable)

    constexpr int f6 = sqr(6); // MUST be evaluated at compile time

   // constexpr int a; // constexpr varaibles must be intitialized

  //  constexpr int f7 = sqr(n); // error : can’t guarantee compile-time evaluation (n is a variable)

    char a1[sqr(4)]; // OK: array bounds must be constants and fac() is constexpr

  //  char a2[sqr(n)]; // error : array bounds must be constants and n is a variable

}
