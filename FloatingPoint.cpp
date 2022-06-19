// FloatingPoint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main()
{
	float f1n{ 365.0f };
	std::cout << "Exponentional Format : " << std::scientific << f1n << std::endl;
	std::cout << "Fxied Format         : " << std::fixed << f1n << std::endl;
	std::cout << "Default Format       : " << std::defaultfloat << f1n << std::endl;

	f1n = -3.650000E-03F;
	std::cout << "Exponentional Format : " << std::scientific << f1n << std::endl;
	std::cout << "Fxied Format         : " << std::fixed << f1n << std::endl;
	std::cout << "Default Format       : " << std::defaultfloat << f1n << std::endl;

	/*floating-point numbers in genaral are only approximate representations of the exact value*/
	f1n = 2'134'311'179;
	std::cout << "Exponentional Format : " << std::scientific << f1n << std::endl;
	std::cout << "Fixed Format         : " << std::fixed << f1n << std::endl;
	std::cout << "Default Format       : " << std::defaultfloat << f1n << std::endl;

	/*adding or subtracting numbers of significantly different magnitudes.*/
	float f2n;
	f1n = 1.23E-4F;//0.000123
	f2n = 3.65E+6F;//3,650,000
	//Expected result after addition 3,650,000.000123
	std::cout << "Addition             : " << std::fixed << (f1n + f2n) << std::endl;

	//catastrophic cancellation

    /*int i1n{ 9 };
    int i2n{};
	std::cout << i1n << " / " << i2n << (i1n / i2n);*/


	//Invalid Floating-point Result
	double d1n{ 1.5 };
	double d2n{};
	double d3n{};
	double result{ d1n / d2n };
	std::cout << d1n << "/" << d2n << "=" << std::endl;
	std::cout << result << "+" << d1n << "=" << (result + d1n) << std::endl;
	result = d2n / d3n;
	std::cout << d2n << "/" << d3n << "=" << result << std::endl;

	//rounding errors

	d1n = 4.0;
	std::cout << std::setprecision(17)   << d1n << std::endl;
	d2n = 0.1 + 0.1 + 0.1 + 0.1;// should equal 1.0
	std::cout << "(0.1 + 0.1 + 0.1 + 0.1) = " << d2n << std::endl;
	std::cout << d1n << " - " << " = "  << (d1n - d2n) << std::endl;
	d1n = (0.1 + 0.1 + 0.1 + 0.1);
	d2n = 0.4;
	if ((d1n - d2n) == 0.0) {
		std::cout << "Equal\n";
	}
	else {
		std::cout << "Different\n";
	}
	std::this_thread::sleep_for(std::chrono::seconds(30));
}

