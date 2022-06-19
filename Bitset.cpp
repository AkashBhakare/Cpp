// Bitset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include <iostream> // std::cin, std::cout
//#include <bitset> // std::bitset
//int main()
//{
//	std::bitset<16> foo;
//	std::cout << "Please, enter a binary number: ";
//	std::cin >> foo;
//	if (foo.any())
//		std::cout << foo << " has " << foo.count() << " bits set.\n";
//	else
//		std::cout << foo << " has no bits set.\n";
//	return 0;
//}

// bitset operators
/*
#include <iostream> // std::cout
#include <string> // std::string
#include <bitset> // std::bitset
int main()
{
	std::bitset<4> foo(std::string("1001"));
	std::bitset<4> bar(std::string("0011"));
std::cout << (foo ^= bar) << '\n'; // 1010 (XOR,assign)
std::cout << (foo &= bar) << '\n'; // 0010 (AND,assign)
std::cout << (foo |= bar) << '\n'; // 0011 (OR,assign)
std::cout << (foo <<= 2) << '\n'; // 1100 (SHL,assign)
std::cout << (foo >>= 1) << '\n'; // 0110 (SHR,assign)
std::cout << (~bar) << '\n'; // 1100 (NOT)
std::cout << (bar << 1) << '\n'; // 0110 (SHL)
std::cout << (bar >> 1) << '\n'; // 0001 (SHR)
std::cout << (foo == bar) << '\n'; // false (0110==0011)
std::cout << (foo != bar) << '\n'; // true (0110!=0011)
std::cout << (foo & bar) << '\n'; // 0010
std::cout << (foo | bar) << '\n'; // 0111
std::cout << (foo ^ bar) << '\n'; // 0101
return 0;
}*/


// constructing bitsets
/*#include <iostream> // std::cout
#include <string> // std::string
#include <bitset> // std::bitset
int main(void)
{
	std::bitset<16> foo;
	std::bitset<16> bar(0xfa2);
	std::bitset<16> baz(std::string("0101111001"));
	std::cout << "foo: " << foo << '\n';
	std::cout << "bar: " << bar << '\n';
	std::cout << "baz: " << baz << '\n';

	return 0;
}*/

// bitset::count
/*#include <iostream> // std::cout
#include <string> // std::string
#include <bitset> // std::bitset
int main()
{
	std::bitset<8> foo(std::string("10110011"));
	std::cout << foo << " has ";
	std::cout << foo.count() << " ones and ";
	std::cout << (foo.size() - foo.count()) << " zeros.\n";
	return 0;
}*/

 /*bitset::flip*/

//#include <iostream> // std::cout
//#include <string> // std::string
//#include <bitset> // std::bitset
//int main()
//{
//	std::bitset<4> foo(std::string("0001"));
//	std::cout << foo.flip(2) << '\n'; // 0101
//	std::cout << foo.flip() << '\n'; // 1010
//	return 0;
//}

 /* bitset::none*/

//#include <iostream> // std::cin, std::cout
//#include <bitset> // std::bitset
//int main()
//{
//	std::bitset<16> foo;
//	std::cout << "Please, enter a binary number: ";
//	std::cin >> foo;
//	if (foo.none())
//		std::cout << foo << " has no bits set.\n";
//	else
//		std::cout << foo << " has " << foo.count() << " bits set.\n";
//	return 0;
//}
//

/*bitset::reset*/

//#include <iostream> // std::cout
//#include <string> // std::string
//#include <bitset> // std::bitset
//int main()
//{
//	std::bitset<4> foo(std::string("1011"));
//	std::cout << foo.reset(1) << '\n'; // 1001
//	std::cout << foo.reset() << '\n'; // 0000
//	return 0;
//}

 /*bitset::set*/

//#include <iostream> // std::cout
//#include <bitset> // std::bitset
//int main()
//{
//	std::bitset<4> foo;
//	std::cout << foo.set() << '\n'; // 1111
//	std::cout << foo.set(2, 0) << '\n'; // 1011
//	std::cout << foo.set(2) << '\n'; // 1111
//	return 0;
//
//}

/* bitset::size*/

//#include <iostream> // std::cout
//#include <bitset> // std::bitset
//int main() {
//	std::bitset<8> foo;
//	std::bitset<4> bar;
//	std::cout << "foo.size() is " << foo.size() << '\n';
//	std::cout << "bar.size() is " << bar.size() << '\n';
//	return 0;
//}


/*bitset::test*/

//#include <iostream> // std::cout
//#include <string> // std::string
//#include <cstddef> // std::size_t
//#include <bitset> // std::bitset
//int main()
//{
//	std::bitset<5> foo(std::string("01011"));
//	std::cout << "foo contains:\n";
//	std::cout << std::boolalpha;
//	for (std::size_t i = 0; i < foo.size(); ++i) {
//		std::cout << foo.test(i) << '\n';
//	}
//	return 0;
//}


/*bitset::to_ulong*/

#include <iostream> // std::cout
#include <bitset> // std::bitset
int main()
{
	std::bitset<4> foo; // foo: 0000
	foo.set(); // foo: 1111
	std::cout << foo << "as an integer is: " << foo.to_ulong();
		return 0;
}
