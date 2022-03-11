// Template_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Typedefs and Alias Declarations
// CTAD

#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
#include <utility>
#include <type_traits>
#include <array>
using namespace std::literals;
struct foo {

};
typedef foo myfoo;
using baz = foo;

void typedef_alias() {
    foo f1;
    myfoo f2;
    baz f3;

    Stack<int> int_stack(5);
    Stack<std::string> str_stack(5);

    //Since C++98
    typedef Stack<int> IntStack;
    IntStack i_stack(4);
    typedef Stack<std::string> StringStack;
    StringStack sstack(4);

    //Since C++11
    using FloatStack = Stack<float>;
    FloatStack fstack(10);

    /*always had to pass all template parameter types to class templates (unless they have default values).*/
    Stack mystk(3);
    mystk.push(45);
    std::cout << mystk.pop() << '\n';
}

void ctad() {

    Queue <int> q1(10);
    //since C++17
    /*if the constructor is able to deduce all template parameters (that don’t have a default value)*/
    Queue  q2(10);
    Queue  q3("Hello"s);

    // MyStack s1;// 

     //CTAD in std lib since CPP17
    std::pair<int, float> int_float_pair(23, 2.3F); //Till C++14
    std::string s{ "Hi" };
    std::pair int_string_pair(23, s); //Since C++17

}


/*
* deduction guides” that tell the compiler how to deduce class template arguments from constructor arguments.
*/
template <typename T1, typename T2>
struct MyPair {
    MyPair() {};
    MyPair(const T1& a, const T2& b) {}

};

MyPair()->MyPair<int, float>; //guide

void adv_ctad() {
    MyPair<int, int> p1(2, 4);
    MyPair<int, double> p2(2, 44.4);
    MyPair p3;
    std::cout << std::boolalpha << std::is_same_v<decltype(p3), MyPair<int, int>> << "\n";
    std::cout << std::boolalpha << std::is_same_v<decltype(p3), MyPair<int, float>> << '\n';
}


template<typename T>
struct ValueWithComment {
    T value;
    std::string comment;
};


ValueWithComment(char const*, char const*)->ValueWithComment<std::string>;

void templatized_aggregates() {
    std::cout << std::boolalpha;
    ValueWithComment<int> vc1;
    vc1.value = 42;
    vc1.comment = "initial value";
    std::cout << "Value : " << vc1.value << "\tComment : " << vc1.comment << '\n';

    std::cout << "vc1 ( T is int ? ) " << std::is_same_v<decltype(vc1), ValueWithComment<int>> << "\n";

    ValueWithComment vc2 = { "hello", "initial value" };
    std::cout << "vc2 ( T is int ? ) " << std::is_same_v<decltype(vc2), ValueWithComment<int>> << "\n";
    std::cout << "vc2 ( T is string ? ) " << std::is_same_v<decltype(vc2), ValueWithComment<std::string>> << "\n";
    std::cout << "vc2 ( T is const char * ? ) " << std::is_same_v<decltype(vc2), ValueWithComment<const char*>> << "\n";

    std::array arr{ 1,2,4,5 };
}

int main()
{
    typedef_alias();
    ctad();
    adv_ctad();
    templatized_aggregates();
}