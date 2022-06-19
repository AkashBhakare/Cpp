// Function11_UsingCallByRef.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*  Write a function which takes a float value as its argument and returns
     1. largest integer not greater than the argument
     2. Smallest ingeter not smaller than the argument
     minmax(12.5F)
         max =  12
         min =  13
     */

#include <iostream>
#include <cstdlib>
#include <cmath>
int minimum(float);
int maximum(float);
int maxmin(float);
void minmax(float, int*, int*);
void minmax_lib(float, int*, int*);

int main()
{
    float f_var{};
    std::cout << "Please enter a float value : ";
    std::cin >> f_var;
    int imax = maximum(f_var);
    int imin = minimum(f_var);
    std::cout << "Maximum : " << imax << "\nMinimum : " << imin << "\n";

    std::cout << "Please enter a float value : ";
    std::cin >> f_var;
    std::cout << maxmin(f_var);

    std::cout << "Please enter a float value : ";
    std::cin >> f_var;
    minmax(f_var, &imax, &imin);
    std::cout << "Maximum : " << imax << "\nMinimum : " << imin << "\n";

    std::cout << "Please enter a float value : ";
    std::cin >> f_var;
    minmax_lib(f_var, &imax, &imin);
    std::cout << "Maximum : " << imax << "\nMinimum : " << imin << "\n";

    return EXIT_SUCCESS;
}

int minimum(float f_var) {
    /* int imin{ (int)f_var };*/
    int imin = static_cast<int>(f_var);
    if (imin < f_var) {
        imin = imin + 1;
    }
    return imin;
}

int maximum(float f_var) {
    /*return (int)f_var;*/
    return static_cast<int>(f_var);
}

int maxmin(float f_var) {
    int imax{ static_cast<int>(f_var) };
    int imin = imax;
    if (imin < f_var) {
        imin = imin + 1;
    }
    /*Function can return only a single value
    When more than one expressions are bind using comma operater only the last
    expression is returned*/
    return imin, imax;
}

void minmax(float f_var, int* ipmax, int* ipmin) {
    *ipmax = static_cast<int>(f_var);
    *ipmin = *ipmax;
    if (*ipmin < f_var) {
        *ipmin = *ipmin + 1;
    }
    return;
}

void minmax_lib(float f_var, int* ipmax, int* ipmin) {
    *ipmax = std::floor(f_var);
    *ipmin = std::ceil(f_var);
    return;
}