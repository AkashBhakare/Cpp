#include <iostream>
#include <boost/algorithm/string.hpp>

int main()
{
	std::string word;
	std::cout << std::endl <<"Please enter your name:";
	std::cin >> word;
	std::cout << "Your name is : " << word << std::endl;
	std::boost::to_upper(word);
	std::cout << "Your name is : " << word << std::endl;
}
