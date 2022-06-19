// Constant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <math.h>
#include <iomanip>
#include <thread>
#include <chrono>
void constant_basics();
void constant_use_case1();
void constant_use_case2();
int main()
{
	//constant_basics();

	//constant_use_case1();
	constant_use_case2();
	//std::this_thread::sleep_for(std::chrono::seconds(25));
}

void constant_basics() {

	const int ci1 = 2;
	std::cout << "ci1 : " << ci1 << std::endl;
	//ci1 = 33;		//error
	//const int ci3; // Error: no value
	//ci3 = 55;
	const float pi = 3.14159f;
	std::cout << "pi  : " << pi << std::endl;
	const char cc = 'a';
	std::cout << "cc  : " << cc << std::endl;
	const bool cmp = ci1 < pi;
	std::cout << "cmp : " << cmp << std::endl;
	int a = 10;
	int b;
	std::cout << "Enter two integers ";
	std::cin >> a >> b;
	const bool flag = a < b;

	std::cout << "flag :" << flag << std::endl;


	//A constexpr variable accepts only compile - time values
	constexpr short scale = 4;
	//constexpr short int scale = 4;
	std::cout << "scale : " << scale << std::endl;
	constexpr bool is_signed = true;
	std::cout << "is_signed : " << is_signed << std::endl;

	std::cout << "is_signed : "
		<< std::setiosflags(std::ios::boolalpha) << is_signed << std::endl;

	std::cout << "is_signed : " << std::boolalpha << is_signed << std::endl;

	constexpr int max = 8 * 1024; //compile time constant
	std::cout << "max : " << max << std::endl;
	constexpr int min = 10;
	constexpr bool flag1 = min < max;

	//constexpr int product = a * b; //the initializer has to be evaluated at compile time
	const int product = a * b; //runtime constant
	std::cout << "product : " << product << std::endl;
	//product = 34;

}

void constant_use_case1() {
	int age;
	std::cout << "What's your age (years) ? ";
	std::cin >> age;
	if (age >= 18) {
		std::cout << "You are eligible to vote!" << std::endl;
	}
	else {
		std::cout << "You are not eligible to vote!" << std::endl;
	}

	//Avoid “magic constants”; use symbolic constants
	constexpr int MIN_AGE_YEAR_FOR_VOTING = 18;
	std::cout << "What's your age (years) ? ";
	std::cin >> age;
	if (age >= MIN_AGE_YEAR_FOR_VOTING) {
		std::cout << "You are eligible to vote!" << std::endl;
	}
	else {
		std::cout << "You are not eligible to vote!" << std::endl;
	}

}


void constant_use_case2() {
	std::cout << "What's the rate of the product(Rs) :";
	float price;
	std::cin >> price;
	std::cout << "How many such products have you purchased ? :";
	float qty_purchased;
	std::cin >> qty_purchased;
	//Avoid “magic constants”; use symbolic constants
	float bill_amount = (price * qty_purchased * 0.05F);
	bill_amount = bill_amount - (bill_amount * 0.02f);

	std::cout << "The bill amount payable is Rs :" << bill_amount << std::endl;

	constexpr float DISCOUNT_RATE = 0.05f;
	constexpr float LOYALTY_DISCOUNT_RATE = 0.02f;

	bill_amount = (price * qty_purchased) * DISCOUNT_RATE;
	bill_amount = bill_amount - (bill_amount * LOYALTY_DISCOUNT_RATE);

	std::cout << "The bill amount payable is Rs :" << bill_amount << std::endl;
}
