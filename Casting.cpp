// Casting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <climits>
//-2147483648  +2147483647

int main()
{
	
	int i1n{};
	int i2n{};
	int isum{};
	float f3n{};

	std::cout << "Enter the first Integer :";
	std::cin >> i1n;
	std::cout << "Enter the second Integer :";
	std::cin >> i2n;

	/*implecit Conversion (Typecasting)*/
     //isum = i1n + i2n;

	/*explicit conversion (typecasting)*/
  
	  isum =( static_cast<long long>(i1n) + i2n);
	 

    std::cout << i1n << " + " << i2n << " = " << isum << std::endl;
	
	
	/* Mixed mode expression*/
	{
		int i1n = 10;
		float f1n = 3.0F;
		int idiv{};

		idiv = i1n / f1n;

	}
	

	i1n = 7;
	i2n = 2;
	f3n = 2.0f;
	f3n = static_cast<float>(i1n) / i2n;

	std::cout << i1n << " / " << i2n << "=" << f3n << std::endl;


	{
		int i1n{};
		int i2n{};
		long long int isum{};
		std::cout << "Enter the first Integer :";
		std::cin >> i1n;
		std::cout << "Enter the second Integer :";
		std::cin >> i2n;
		isum = static_cast<long long>(i1n + i2n);
		std::cout << i1n << " + " << i2n << " = " << isum << std::endl;

	}

	std::this_thread::sleep_for(std::chrono::seconds(25));
}
