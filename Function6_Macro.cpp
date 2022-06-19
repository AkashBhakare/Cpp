// Function6_Macro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

void foo();
void goodPart();
void badPart();
void uglyPart();
void bar();
void baz();

#define STARLINE "**************************************\n"

#define sqr(x) x * x

#define min(x,y) (((x) < (y)) ? (x) : (y))

int main()
{
    foo();
    goodPart();
    badPart();
    uglyPart();
    bar();
    baz();
    return EXIT_SUCCESS;
}

void foo() {
    std::cout << STARLINE;
    std::cout << "Entered foo\n";
    std::cout << "Successfully returning from foo\n";
    std::cout << STARLINE;
    return;
}


void goodPart() {
    int inum = 2;
    std::cout << "Square of " << inum << " = " << sqr(inum) << std::endl;
    std::cout << "Square of " << 10 << " = " << sqr(10) << std::endl;
    std::cout << "Min of 3,5 is : " << min(3, 5) << std::endl;
}
void badPart() {
    std::cout << "Square of " << (2 + 3) << " = " << sqr(2 + 3) << std::endl;
}

void  uglyPart() {
    int a = 10;
    int b = 20;
    std::cout << "Minimum is" << min(a++, b++) << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}

void bar() {
    //No Scoping
#define MAX_AGE 60
    std::cout << "Max age in bar : " << MAX_AGE << std::endl;
    return;
}

void baz() {
    std::cout << "Max age in baz : " << MAX_AGE << std::endl;
    return;
}