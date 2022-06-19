// auto_keyword.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
#include <thread>
#include <chrono>
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
#include <climits>
#include <cinttypes>
#include <intsafe.h>

char doit(const char ch) {
    return (char)std::toupper(ch);
}

int addit(int n1, int n2) {
    return n1 + n2;
}

int main()
{

    /*{
        std::cout << "Type of 3.14  :" << typeid(3.14).name() << std::endl;
        std::cout << "Type of 3.14F :" << typeid(3.14f).name() << std::endl;
        int i = 12;
        std::cout << "Type of i     :" << typeid(i).name() << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(7));
    }*/

    {
        /*To declare local variables with the form
          auto name = expression
          when you do not want to commit to a specific type :*/
        auto i1n = 42; // int
        std::cout << "Type of i1n : " << typeid(i1n).name() << std::endl;

        auto i2n{ 42 }; // int
        std::cout << "Type of i2n : " << typeid(i2n).name() << std::endl;

        auto i3n = { 42 }; // std::initializer_list<int>
        //std::cout << i3n * 5; // error
        std::cout << "Type of i3n : " << typeid(i3n).name() << std::endl;

        auto d = 42.5; // double
        std::cout << "Type of d : " << typeid(d).name() << std::endl;

        auto s1 = "text"; // char const *
        std::cout << "Type of s : " << typeid(s1).name() << std::endl;

        //auto s2 = "Hello!"s; // a std::string
        //std::cout << "type of s : " << typeid(s2).name() << std::endl;


        auto v1 = { 1, 2, 3 }; // std::initializer_list<int>
        std::cout << "Type of v1 : " << typeid(v1).name() << std::endl;

        auto v2 = { 1.1, 2.1, 3.3 }; // std::initializer_list<int>
        std::cout << "Type of v2 : " << typeid(v2).name() << std::endl;

        int roll = 12;
        auto var = roll;
        std::cout << "Type of var : " << typeid(var).name() << std::endl;


        //std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    {
        /* To declare local variables with the
           auto name = type-id{ expression }
           form when you need to commit to a specific type :*/
        auto b = new char[10]{ 0 }; // char*
        std::cout << "Type of b : " << typeid(b).name() << std::endl;

        auto s1 = "text"; // const char*
        std::cout << "Type of s1 : " << typeid(s1).name() << std::endl;

        auto s2 = std::string{ "text" }; // std::string
        std::cout << "Type of s2 : " << typeid(s2).name() << std::endl;

        auto v1 = std::vector<int>{ 1, 2, 3 }; // std::vector<int>
        std::cout << "Type of v1 : " << typeid(v1).name() << std::endl;

        auto p = std::make_shared<int>(42); // std::shared_ptr<int>
        std::cout << "Type of p : " << typeid(p).name() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(10));

    }

    {
        /*To declare named lambda functions, with the form
        auto name = lambdaexpression,
        unless the lambda needs to be passed or returned to a function :*/
        std::cout << doit('q') << std::endl;
        std::cout << "Addit : " << addit(30.55, 50.3) << std::endl;

        auto upper = [](char const ch) {std::cout << (char)toupper(ch) << " "; };

        auto data = std::vector<char>{ 'a','b','c','d' };
        std::for_each(data.begin(), data.end(), upper);


        std::cout << std::endl;
        //std::this_thread::sleep_for(std::chrono::seconds(5));

    }

    {
        //To declare lambda parameters and return values:
        auto add = [](auto const a, auto const b) {return a + b; };

        std::cout << "Addition of integers: " << add(10, 20) << std::endl;
        std::cout << "Addition of double  : " << add(10.5, 20.7) << std::endl;

        std::string s1 = "Robin";
        std::string s2 = "Singh";
        std::cout << "Addition of Strings: " << add(s1, s2) << std::endl;
        //  std::cout << "Addition of Strings: " << add("Rishi"s,"Kapoor"s) << std::endl;
          //std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    {
        /*Using auto ensures that you always use the correct
        typeand that implicit conversion will not occur*/
        auto v = std::vector<int>{ 1, 2, 3 };
        std::cout << "Max size for vector :" << v.max_size() << std::endl;
        // v.resize(INT32_MAX + 10);
        std::cout << "Type of v     :" << typeid(v).name() << std::endl;

        // implicit conversion, possible loss of data
        auto x = 4611686018427387903LL;
        std::cout << "X" << x << std::endl;
        /* int size1 = v.size();
         std::cout << "Size1 :" << size1 << "type :"<< typeid(size1).name() <<  std::endl;
    */
        auto size2 = v.size();
        std::cout << "Size2 :" << size2 << "type : " << typeid(size2).name() << std::endl;

        // ill-formed (warning in gcc/clang, error in VC++)
   //     auto size3 = int{ v.size() };
        std::this_thread::sleep_for(std::chrono::seconds(15));
    }
    {
        /* It is not possible to use auto for multi - word types,
          such as long long, long  double, or struct foo.
          However, in the first case, the possible workarounds
          are to use literals or type aliases; as for the second,
          using struct / class in that form is only supported in
          C++ for C compatibilityand should be  avoided anyway :*/
          //auto l1 = long long{ 42 }; // error
          //using llong = long long;
          //auto l2 = llong{ 42 }; // OK
          //auto l3 = 42LL; // OK

    }
}
