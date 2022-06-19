// function1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void doit(); //Function declaration
int foo(int); //Functuion Declaration
double avg(double, double);
int add(int, int);

void printOddNumber(int number_of_odd_values);

int main()
{
        doit();  // Function Call
        doit();  // Function Call
        doit();  // Function Call
        //foo(45);
        std::cout << "Addition of 3 & 4 is  : " << (3 + 4) << std::endl;
        std::cout << "Average of 5.5 & 6.7 is: " << avg(5.5, 6.7) << std::endl;
        /* A function call is an expression as long as it returns value other than void*/
        std::cout << "Addition of  4 & Average of 5.5 & 6.7 is: "
            << (4 + avg(5.5, 6.7)) << std::endl;
        /*Since doit returns void; it cannot be a part of expression*/
       // std::cout << "Addition of  4 & doit :" << ( 4 + doit()) << std::endl;
    
        double result = avg(3.4, 5.6);
        std::cout << "Average of 3.4 & 5.6 = " << result << std::endl;
    
        /*Argumments of type integer are implicitely promoted to double
        * Its safe because smaller type int it promoted to larger type double
       */
        result = avg(10, 15);
        std::cout << "Average of 10 & 15 = " << result << std::endl;
    
        int sum = add(10, 20);
        std::cout << "Addition of 10 & 20 = " << sum << std::endl;
    
        /*
        Unsafe : beacuse lafger type double is converted to smaller type int.
        This will result into loss of precision or loss of data
        */
        sum = add(10.5, 20.6); //Loss of precision
        std::cout << "Addition of 10.5 & 20.6 = " << sum << std::endl;
    
        result = add(10.5, 20.6); //Loss of precision
        std::cout << "Addition of 10.5 & 20.6 = " << result << std::endl;
    
        result = add(7000000000.5, 2000000000.4); //Loss of data
        std::cout << "Addition of 7000000000.5 & 2000000000.4 = "
            << std::fixed << result << std::endl;
    
        printOddNumber(5);
        return 0;
    }
    
    void doit() { //Function definition
        std::cout << "Starting the task.." << std::endl;
        std::cout << "Completed the task.." << std::endl;
        return;
    }
   
    //float foo(std::string) {
    //    return 1.0f;
    //}
    
    double avg(double d1n, double d2n) {
        return (d1n + d2n) / 2;
    }
    
    int add(int i1n, int i2n) {
        return (i1n + i2n);
    }
    
    void printOddNumber(int number_of_odd_values)
    {
        std::cout << "The first " << number_of_odd_values << " odd values are :\n";
        for (int odd{ 1 }; odd <= (2 * number_of_odd_values); odd += 2) {
            std::cout << odd << ", ";
        }
        std::cout << std::endl;

    }

    void printEvenNumber(int number_of_even_values)
    {
        std::cout << "The first" << number_of_even_values << " even values are :\n";
        for (int even{ 1 }; even <= (2 * number_of_even_values); even += 2) {
            std::cout << even << " , ";
        }
        std::cout << std::endl;
    }
