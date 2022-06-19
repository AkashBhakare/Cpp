// Function19_main_agrs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <cstdlib>
//
//int main(int argc, char* argv[])
//{
//    const int EXPECTED_NUMBER_OF_ARGS{ 3 };
//
//    if (argc != EXPECTED_NUMBER_OF_ARGS) {
//        std::cerr << "The syntax of the command is incorrect.\n";
//        std::cerr << "Usage calc <value> <operator> <value>\n";
//        exit(EXIT_FAILURE);
//    }
//
//    int i1n = std::atoi(argv[1]);
//    int i2n = std::atoi(argv[2]);
//    std::cout << argv[1] << " + " << argv[2] << " = " << (i1n + i2n) << "\n";
//    return EXIT_SUCCESS;
//}

// Function19_main_agrs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

 // calc 36 + 57

double operate(double d1n, double d2n, char sign) {
	switch (sign) {
	case '+':
		return (d1n + d2n);
	case '-':
		return (d1n - d2n);
	case 'x':
		return (d1n * d2n);
	case '/':
		return (d1n / d2n);
	case '%':
		return ((int)d1n % static_cast<int>(d2n));
	case '$':
		return (std::pow(d1n, d2n));
	default:
		std::cerr << "Invalid expression!\n";
		exit(EXIT_FAILURE);
	}

}

int main(int argc, char* argv[])
{
	const int EXPECTED_NUMBER_OF_ARGS{ 4 };

	if (argc != EXPECTED_NUMBER_OF_ARGS) {
		std::cerr << "The syntax of the command is incorrect.\n";
		std::cerr << "Usage calc <value> <operator> <value>\n";
		exit(EXIT_FAILURE);
	}

	double d1n = std::atof(argv[1]);
	char sign = argv[2][0];
	double d2n = std::atof(argv[3]);

	auto result = operate(d1n, d2n, sign);
	std::cout << argv[1] << " " << sign << " " << argv[3] << " = ";
	// std::cout << std::fixed << std::setprecision(3) << result << "\n";
	std::cout << std::setprecision(3) << result << "\n";
	return EXIT_SUCCESS;
}
