// Function12_tuple_introduction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <tuple>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
void tuple_introduction1();
void tuple_introduction2();

void make_tuple_demo();

int main()
{
    //tuple_introduction1();
  // tuple_introduction2();
    //make_tuple_demo(); 

    return EXIT_SUCCESS;
}

void tuple_introduction1() {
    /*
    A tuple is a generalization of a pair, an ordered set of heterogeneous elements.
    One way to imagine using a tuple is to hold a row of data in a database.
    The row might contain the attributes of a person, such as the
    person's name, age, height, and so on.
    All the elements might have different types, but they all belong together as
    one row.
    */
    std::tuple<std::string, int, float> rec_tup{ "Akash",20,5.7f };
    // get elements by index
    std::cout << "Get elements of the tuple by index\n";
    std::cout << "Name   : " << std::get<0>(rec_tup) << std::endl;
    std::cout << "Age    : " << std::get<1>(rec_tup) << " years" << std::endl;
    std::cout << "Height : " << std::get<2>(rec_tup) << " ft" << std::endl;

    std::cout << "Get elements of the tuple by their type\n";
    // get elements by type
    std::cout << "Name   : " << std::get<std::string>(rec_tup) << std::endl;
    std::cout << "Age    : " << std::get<int>(rec_tup) << " years" << std::endl;
    std::cout << "Height : " << std::get<float>(rec_tup) << " ft" << std::endl;


}

//   typedef existing_type_name  additional_name
void tuple_introduction2() {
    typedef int integer;
    typedef std::tuple<integer, double, double> iddtuple;

    std::vector <iddtuple> vec;
    for (int i = 1; i <= 10; i++)
    {
        vec.push_back(iddtuple(i, std::pow(i, 2), std::pow(i, 3)));
    }

    for (iddtuple tup : vec)
    {
        std::cout << "Number : " << std::setw(5) << std::get<0>(tup) << '\t';
        std::cout << "Square : " << std::setw(5) << std::get<1>(tup) << '\t';
        std::cout << "Cube   : " << std::setw(5) << std::get<2>(tup) << '\n';
    };
    return;
}

void make_tuple_demo() {

    typedef std::tuple<int, double, int, double> Mytuple;

    Mytuple c0(0, 1.5, 2, 3.5);

    // display contents " 0 1 2 3"
    std::cout << std::get<0>(c0) << " ";
    std::cout << std::get<1>(c0) << " ";
    std::cout << std::get<2>(c0) << " ";
    std::cout << std::get<3>(c0) << std::endl;

    std::tuple<int, double, int, double> c1;
    c1 = std::make_tuple(4, 5.5, 6, 7.7);

    // display contents " 4 5 6 7"
    std::cout << std::get<0>(c1) << " ";
    std::cout << std::get<1>(c1) << " ";
    std::cout << std::get<2>(c1) << " ";
    std::cout << std::get<3>(c1) << std::endl;

    /*Creates a tuple object, deducing the target type from the types of arguments.*/
    auto c2 = std::make_tuple(14, 15.5, 16, 17.7);

    // display contents " 4 5 6 7"
    std::cout << std::get<0>(c2) << " ";
    std::cout << std::get<1>(c2) << " ";
    std::cout << std::get<2>(c2) << " ";
    std::cout << std::get<3>(c2) << std::endl;

    return;
}