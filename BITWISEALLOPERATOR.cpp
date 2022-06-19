// BITWISEALLOPERATOR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <bitset>
#include <iostream>
int main()
{
	//Bitwise left shift operator (<<)
   /*
   {
		std::bitset<4> x{ 0b1100 };

		std::cout << x << '\n';
		// shift right by 1, yielding 0110
		std::cout << (x >> 1) << '\n';

		// shift left by 1, yielding 1000
		std::cout << (x << 1) << '\n';
	}*/

	//BITWISE RIGHT SHIFT OPERATOR
	/*
	unsigned int x{ 0b0100 };
	// use operator<< for left shift
	x = x << 1;
	// use operator<< for output
	std::cout << std::bitset<4>{ x };
	*/
	// LEFT SHIFT OPERATOR

   /* std::bitset<4> x { 0b0110 };
	// print value of x (0110), then 1
	std::cout << x << 1 << '\n';
	// print x left shifted by 1 (1100)
	std::cout << (x << 1) << '\n';
	*/
	//BITWISE NOT OPERATOR
	/*
	std::cout << std::bitset<4>{ ~0b0100u }
	<< ' ' << std::bitset<8>{ ~0b0100u };
	*/

	// BITWISE OR
	/*
	0 1 0 1 OR
	0 1 1 0
	------ -
	0 1 1 1

	std::cout <<
		(std::bitset<4>{ 0b0101 } | std::bitset<4>{ 0b0110 });
	return 0;

	 0 1 1 1 OR
		0 0 1 1 OR
		0 0 0 1
		--------
		0 1 1 1
		   std::cout <<
		   (std::bitset<4>{ 0b0111 } |
			std::bitset<4>{ 0b0011 } |
			std::bitset<4>{ 0b0001 });
			return 0;
   */
   //BITWISE AND
		  /*  0 1 0 1 AND
			0 1 1 0
			--------
			0 1 0 0

			std::cout << (
				std::bitset<4>{ 0b0101 } &std::bitset<4>{ 0b0110 });


			0 0 0 1 AND
			0 0 1 1 AND
			0 1 1 1
			--------
			0 0 0 1
		std::cout << (std::bitset<4>{ 0b0001 } &
			std::bitset<4>{ 0b0011 } &
			std::bitset<4>{ 0b0111 });
			*/

			//BITWISE XOR
			   /* 0 1 1 0 XOR
				0 0 1 1
				------ -
				0 1 0 1

				0 0 0 1 XOR
				0 0 1 1 XOR
				0 1 1 1
				--------
				0 1 0 1

				std::bitset<4> bits{ 0b0100 };
				bits >>= 1;
				std::cout << bits;
				*/

//QUIZ TIME
	// "rotl" stands for "rotate left"
	std::bitset<4> rotl(std::bitset<4> bits)
	{
		// Your code here
	}
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';
	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';
	return 0;
}

