// Template_1.cpp : 
// Need for templates

#include <iostream>
#include <string>
#include <complex>
#include <algorithm>
using namespace std::literals;

struct Person {
	Person(std::string name) {
		this->name = name;
	}
	std::string name;

};

std::ostream& operator<<(std::ostream& out, const Person p) {
	out << p.name;
	return out;
}

void display(int value) {
	std::cout << "Value : " << value << '\n';
}

void display(std::string value) {
	std::cout << "Value : " << value << '\n';
}

void display(double value) {
	std::cout << "Value : " << value << '\n';
}

void display(Person value) {
	std::cout << "Value : " << value << '\n';
}

int add(int n1, int n2) {
	return n1 + n2;
}

double add(double n1, double n2) {
	return n1 + n2;
}



void using_function_overload() {
	display(55);
	display("Aman"s); //Error
	display(12.5); //Loss of precision
	display(Person("Raja"));
	std::cout << "add(10,20)     : " << add(10, 20) << '\n';
	std::cout << "add(10.5,20.6) : " << add(10.5, 20.6) << '\n';
}

template<typename T>
T max(const T& arg1, const T& arg2) {
	//std::cout << "Our max : ";
	if (arg1 > arg2)
		return arg1;
	return arg2;
}

template<typename T1, typename T2>
T2 min(const T1& arg1, const T2& arg2) {
	//std::cout << "Our min : ";
	if (arg1 < arg2)
		return arg1;
	return arg2;
}


//Explicit specialization
int max(const int& arg1, const int& arg2) {
	//std::cout << "Our max : ";
	if (arg1 > arg2)
		return arg1;
	return arg2;
}

void using_template() {
	std::cout << "Maximum of 10, 20 : " << std::max(10, 20) << '\n';			// from std lib

	std::cout << "Maximum of 10, 20        : " << ::max(10, 20) << '\n';					// integer
	std::cout << "Maximum of 10.5, 10.20   : " << ::max(10.5, 10.20) << '\n';			// double
	std::cout << "Maximum of 'Rama', 'Lala': " << ::max("Rama"s, "Lala"s) << '\n'; // std::string
	std::cout << "Maximum of 10.5, 20.5    : " << ::max(10.5L, 20.5L) << '\n';				// long double
	std::cout << "Maximum of 101, 120      : " << ::max(101, 120) << '\n';				// integer
}

void problem_instanciating() {
	//std::cout << "Maximum of 10, 20 : " << ::max(10, 20.5) << '\n';					// integer
	std::cout << "Minimum of 10, 20 : " << ::min(10, 20.5) << '\n';
	std::cout << "Minimum of 101, 120 : " << ::min(101, 120) << '\n';
}


template<typename T>
long double average(const T& arg1, const T& arg2) {
	return (static_cast<long double>(arg1) + arg2) / 2.0;
}

template<typename T>
long double average(const T& arg1, const T& arg2, const T& arg3) {
	return (static_cast<long double>(arg1) + arg2 + arg3) / 2.0;
}

void overloading_function_template() {
	std::cout << "Average of 10, 20     : " << average(10, 20) << '\n';
	std::cout << "Average of 10, 20, 25 : " << average(10, 20, 25) << '\n';
}

/*Mix of Generic and standard type in template function*/
template <typename T>
void print(const T arr[], size_t size) {
	for (size_t idx{ 0 }; idx < size; ++idx) {
		std::cout << arr[idx] << ", ";
	}
	std::cout << '\n';
}

void standard_and_generic_pameter_mix() {
	int iarr[]{ 23,45,67,89,90 };
	print(iarr, std::size(iarr));

	double darr[]{ 2.3,4.5,6.7,8.9,9.6 };
	print(darr, std::size(darr));

	std::string sarr[]{ "Saurav"s, "Sachin"s, "Rahul"s,"Vinod"s };
	print(sarr, std::size(sarr));
}

int main()
{
	using_function_overload();
	using_template();
	problem_instanciating();
	overloading_function_template();
	standard_and_generic_pameter_mix();
}