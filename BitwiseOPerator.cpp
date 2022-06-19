// BitwiseOPerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <bitset>
#include <iostream>
#include <thread>
#include <cmath>
int main()
/*One's Compliment */

	//		unsigned char cdata1 = 'A';
	//  
	//    unsigned char cdata2 = ~cdata1;
	//
	//    std::cout << "character 1 : " << cdata1 <<
	//        "\tCharacter Code  : " << static_cast<int>(cdata1) <<
	//        "\t(Binary) " << std::bitset<8>(cdata1) << std::endl;
	//
	//    std::cout << "character 2 : " << cdata2 <<
	//        "\tCharacter Code  : " << static_cast<int>(cdata2) <<
	//        "\t(Binary) " << std::bitset<8>(cdata2) << std::endl;
	//
	//    unsigned int idata1 = 1005U;
	//    unsigned int idata2 = ~idata1;
	//
	//    std::cout << "Integer data1 : " << idata1 << std::endl <<
	//         "\t(Binary) " << std::bitset<32>(idata1) << std::endl;
	//   std::cout << "Integer data2 : " << idata2 << std::endl<<
	//        "\t(Binary) " << std::bitset<32>(idata2) << std::endl;
	//
	//}

/*Left Shift*/
/*{
	int i1n = 100;
	int ibitpos = 1;
	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;
	int iresult = i1n << ibitpos;
	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<16>(iresult) << std::endl;

	i1n = -7;
	ibitpos = 5;
	std::cout << "Integer i1n : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<32>(i1n) << std::endl;
	iresult = i1n << ibitpos;
	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<32>(iresult) << std::endl;

}*/

/*Right Shift*/
/*{
	int i1n = 100;
	int ibitpos = 1;
	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;
	int iresult = i1n >> ibitpos;
	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<16>(iresult) << std::endl;

	i1n = -7;
	ibitpos = 5;
	std::cout << "Integer i1n : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<32>(i1n) << std::endl;
	iresult = i1n >> ibitpos;
	std::cout << "Integer result : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<32>(iresult) << std::endl;

}*/

{
/*Bitwise And : & : bit_and*/
/*Check bit status
	01100100                01100100
	00010000                00100000
	_________               _________
	00000000                00100000
 */
 {
	 int i1n     = 100;
	 int ibitpos = 7;
	 std::cout << "Integer i1n    : " << i1n << std::endl <<
		 "\t(Binary) " << std::bitset<16>(i1n) << std::endl;

	 int iresult = i1n & static_cast<int>(pow(2,(ibitpos-1)));

	 if (iresult == 0) {
		 std::cout << "\tBit position " << ibitpos << " is Off"
			 << std::endl;
	 }
	 else
	 {
		 std::cout << "\tBit position " << ibitpos << " is ON"
			 << std::endl;
	 }
 }

 /* Turn off a bit
	 01100100                01100100
	 11111011                11011111
	 _________               _________
	 01100000                01000100

	 bitpos = 3
	 mask = pow(2,(bitpos-1))
	 mask : 4 =>    00000100
	 ~mask :        11111011
  */
/*{
	int i1n = 100;
	int ibitpos = 6;
	std::cout << "Integer i1n    : " << i1n << std::endl <<
		"\t(Binary) " << std::bitset<16>(i1n) << std::endl;

	int mask = static_cast<int>(pow(2, (ibitpos - 1)));
	mask = ~mask;
	int iresult = i1n & mask;

	std::cout << "Integer iresult : " << iresult << std::endl <<
		"\t(Binary) " << std::bitset<16>(iresult) << std::endl;
}*/

std::this_thread::sleep_for(std::chrono::seconds(25));
  
}