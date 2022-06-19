// Cpp_Triva_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>


auto format(const std::string& book_title, const std::string& author) {
    return book_title + " : " + author;
}
int main() {
    // write c++ code here
    std::string book_title = "system performance";
    std::string author = "brendan gregg";
    //std::string_view output = format(book_title, author);
    //std::cout << output << "\n";

    return 0;
}

//#include <iostream>
//#include <optional>
//
//int main()
//{
//    int i = 2;
//    int& ref1 = i;
//    std::optional<int&> opt(ref1);
//
//    int j = 3;
//    opt = j;
//    std::cout << opt.value();
//    return 0;
//}
