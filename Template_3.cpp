// Template3.cpp : 
// Explicitly selecting version of a function template

#include <iostream>
#include <concepts>
template <typename T>
void print(const T& data_ref) {
    std::cout << "Printing : " << data_ref << '\n';
}

void show(const auto& ref) {
    std::cout << "Showing : " << ref << '\n';
}

/*With concept*/
void display(const std::unsigned_integral auto& ref) {
    std::cout << "display : " << ref << '\n';
}

template <typename T>
void doit() {
    T data;
    std::cout << "Size of Template type : " << sizeof(T) << '\n';
}

template<typename T>
void addit(const T& ref) {
    std::cout << "After adding : " << (ref + ref) << '\n';
}

int main()
{
    print('A');
    print("String");
    print(12);
    print(1.2);
    print(1.2f);

    show('A');
    show("String");
    show(12);
    show(1.2);
    show(1.2f);


  /*display('A');
    display(-12);*/
    display(12u);
    /* display("String");
     display(1.2);
     display(1.2f);*/

     // doit(); // could not deduce template argument for 'T'	
    doit<int>();
    doit<float>();
    doit<double>();

    addit(6);
    addit(6.6);
    // addit("Hello"); // reference to function template instantiation 'void addit<char[6]>(const T (&))' being compiled	Template3	D : \TC\Cpp\CppBasics\Template3\Template3.cpp	60
    addit<std::string>("Hello ");
    //compiler to do certain conversion on the arguments before selecting the correct
    addit<int>(6.5);

    display<unsigned int>(4.5);
}