// Function2_return.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>

//error C4716 : 'f1' : must return a value
//int  f1() { 
//    std::cout << "I am in f2\n";
//    // error : no value returned
//   
//} 

void f2() {
    std::cout << "I am in f2\n";
    // OK
    //��Falling off the end�� of a function; 
}

int  f3() {
    std::cout << "I am in f3\n";
    return 11; // OK
}

// error C2562: 'f4': 'void' function returning a value
//void f4() {  
//   return 1; // error: return value in void function
//} 

// error C2561 : 'f5' : function must return a value
//int  f5() { 
//   return;  // error : return value missing
//   
//}   

void f6() {
    std::cout << "I am in f6\n";
    return; // OK
}

//error C4430 : missing type specifier - int assumed.
//Note : C++ does not support default - int
//f7() {
//    std::cout << "I am in f7\n";
//    return 99;
//}

int baz(int x) {
    if (x == 0) {
        throw std::exception("0 is out of range!"); //Throwing an exception
    }

    if (x < 0) {
        std::exit(1);//invoking a system function that doesn�t return
    }
    return x * x;
}

int main(void)
{
    //std::cout << "Calling f1 : " << f1() << std::endl;
    f2();
    std::cout << "Calling f3 : " << f3() << std::endl;
    f6();
    std::cout << "Baz returned " << baz(10) << std::endl;
    try {
        std::cout << "Baz returned " << baz(0) << std::endl;
    }
    catch (std::exception& err) {
        std::cout << err.what();
    }
    std::cout << "Baz returned " << baz(-8) << std::endl;
    std::cout << "finished with main!\n";
    return 0;
}
