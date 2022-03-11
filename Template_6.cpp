// Template_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Variadic Templates*/


#include <iostream>
#include <cassert>
#include <string>
#include <complex>
#include <vector>

using namespace std::literals;

/* To end the recursion, the nontemplate overload of print() is provided,
   which is issued when the parameter pack is empty*/
void print()
{
	std::cout << "All arguments processed\n";
}

//template<typename T>
//void print(T lastArg)
//{
//	std::cout << lastArg << '\n';
//	std::cout << "Last arguments processed\n";
//}


template<typename T, typename... Types>
void print(T firstArg, Types... args)
{
	std::cout << firstArg << '\n';	// print first argument
	print(args...);					// call print() for remaining arguments
}

void variadic_template_basics() {
	std::string s("world");
	print(7.5, "hello", s);
	/*
	The call first expands to		: print<double, char const*, std::string> (7.5, "hello", s);
	The Second call then expands to : print<char const*, std::string> ("hello", s);
	The Second call then expands to : print<std::string> (s);
	Now args being an empty variadic template argument having no value. Thus, after printing "world" as firstArg,
	we calls print() with no arguments, which results in calling the nontemplate overload of print() doing nothing.

	*/
}

/*===================================================================================================================*/


void printing()
{
	std::cout << "All arguments processed\n";
}


//sizeof... Queries the number of elements in a parameter pack.
template<typename T, typename... Types>
void printing(T firstArg, Types... args)
{
	static size_t pass_counter{ 1 };
	std::cout << "\nPass number : " << pass_counter++ << '\n';
	std::cout << "Remaining number of types : " << sizeof...(Types) << '\n'; // print number of remaining types
	std::cout << "Remaining number of Args  : " << sizeof...(args) << '\n';  // print number of remaining args
	printing(args...);
}

void variadic_size_of_demo() {

	printing(7.5, "hello", "world"s);
	printing(5, 4.5, "hello", "world"s);
}


/*===================================================================================================================*/

template<typename T, typename... Types>
void print_if(T const& firstArg, Types const&... args)
{
	int i{ 30 };
	std::cout << firstArg << '\n';
	if constexpr (sizeof...(args) > 0) {
		print_if(args...);				// code only available if sizeof...(args)>0 (since C++17)
	}
}

void compile_time_if_demo() {

	print_if(7.5, "hello", "world"s);
}

/*===================================================================================================================*/

template<typename T>
void undeclared(T t) {
	std::cout << t << " undeclared(t) invoked\n";
}


void undeclared() {
	std::cout << "undeclared(void) invoked\n";
}

template<typename T>
void foo(T t)
{
	if constexpr (std::is_integral_v<T>) { //compiletime expression that yields a Boolean value
		std::cout << "Value : " << t << '\n';
		if (t > 0) {
			foo(t - 1); // OK
		}
	}
	else {
		undeclared(t); // error if not declared and not discarded (i.e. T is not integral)
		undeclared(); // error if not declared (even if discarded)
		//Performs compile - time assertion checking.
		//static_assert(false, "no integral"); // always asserts (even if discarded)
		static_assert(!std::is_integral_v<T>, "no integral"); // OK
	}
}


void constexpr_if() {
	//foo("Abc");
	foo(4);
}

/*===================================================================================================================*/

template<typename... T>
void printDoubled(T const&... args)
{
	print(args + args...);
}

template<typename... T>
void addOne(T const&... args)
{
	//print(args + 1...); // ERROR: 1... is a literal with too many decimal points
	//print(args + 1 ...); // OK
	print((args + 1)...); // OK
}


void variadic_expression() {
	//printDoubled(7.5, std::string("hello"), std::complex<float>(4, 2));
	//addOne(3.4, 2, 10u);
}


/*===================================================================================================================*/

template<typename C, typename... Idx>
void printElems(C const& coll, Idx... idx)
{
	print(coll[idx]...);
}

//We can also declare nontype template parameters to be parameter packs.
template<std::size_t... Idx, typename C>
void printIdx(C const& coll)
{
	print(coll[Idx]...);
}


void variadic_indices() {
	std::vector<std::string> coll = { "good", "times", "say", "bye" };
	//printElems(coll, 2, 0, 3); //effect is to call 	print(coll[2], coll[0], coll[3]);
	printIdx<2, 0, 3>(coll);


}


/*===================================================================================================================*/

template<typename... Types>
void printall(Types const&... args)
{
	(std::cout << ... << args) << '\n';
}


/*
* unary left fold
* It reduces/folds the parameter pack of integers into a single integer by
* applying the binary operator successively.
* It's unary because it does not explicitly specify an init (a.k.a. identity) argument.
* Unary Left Fold (... op pack) which expands as follows:
	((Pack1 op Pack2) op ...) op PackN
*/
template<typename... T>
auto foldSumLeft(T... args) {
	return (... + args); // ((args1 + args2) + args3) ...
}

/*
* unary right fold
* It reduces/folds the parameter pack of integers into a single integer by
* applying the binary operator successively.
* It's unary because it does not explicitly specify an init (a.k.a. identity) argument.
* Unary Right Fold (pack op ...) which expands as follows:
	Pack1 op (... (Pack(N-1) op PackN))
*/
template<typename... T>
auto foldSumRight(T... args) {
	return (args + ...); // (args1 + ( args2 + ( args3 + args4 )))
}

void fold_expr_basic() {
	std::cout << foldSumLeft(1, 2, 3, 4, 5); //It's equivalent to ((((1+2)+3)+4)+5).
	std::cout << "\n";
	std::cout << foldSumRight(1, 2, 3, 4, 5); //It's equivalent to (1+(2+(3+(4+5)))).
	std::cout << "\n";
	printall(1, 2, 3, 4, 5);
	std::cout << "\n";

}

/*===================================================================================================================*/

/*
  binary left fold.
  Binary Left Fold - (value op ... op pack) - Expands as follows:
	(((Value op Pack1) op Pack2) op ...) op PackN
  The init argument is 0 and it's redundant (in this case).

*/

template <typename... Args>
auto addall(Args... args)
{
	return (0 + ... + args); //The init argument is 0 and it's redundant (in this case).
	// That's because this fold expression is equivalent to(((((0 + 1) + 2) + 3) + 4) + 5).
}

struct Int {
	int value;
	explicit Int(int v = 0) : value(v) {}
	explicit operator int() const { return value; }
	explicit operator float() const { return static_cast<float>(value); }
};

std::ostream& operator << (std::ostream& o, const Int& i) {
	o << i.value;
	return o;
}

Int operator + (Int const& i, Int const& j) {
	std::cout << "Adding " << i << " " << j << "\n";
	return Int(i.value + j.value);
};

Int operator * (Int const& i, Int const& j) {
	std::cout << "Multiplying " << i << " " << j << "\n";
	return Int(i.value * j.value);
};

//left fold
template<typename... Args>
auto addInts(Args&&... args)
{
	return (Int{ 0 } + ... + args);
}

//left fold
template<typename... Args>
auto mulInts1(Args&&... args)
{
	return (Int{ 1 } * ... * args);
}

//right fold
template<typename... Args>
auto mulInts2(Args&&... args)
{
	return (args * ... * Int{ 1 });
}


/*
  binary right fold.
  Binary Right Fold (pack op ... op value) - Expands as follows:
	Pack1 op (... op (Pack(N-1) op (PackN op Value)))
*/
template<typename ...Args>
auto sum1(Args ...args)
{
	return (args + ... + 0);  // (1+(2+(3+(4+0))))
}

// or even: Unary right fold

template<typename ...Args>
auto sum2(Args ...args)
{
	return (args + ...);
}


void binary_fold() {
	/*std::cout << "addall : " << addall(1, 2, 3, 4, 5) << '\n';
	std::cout << "\n";*/


	/*std::cout << sum1(1, 2, 3, 4, 5) << "\n";
	std::cout << sum2(1, 2, 3, 4, 5) << "\n";*/

	//Int v1(10);
	//int i = int(v1);
	//float f = float(v1);

	std::cout << addInts(Int{ 1 }, Int{ 2 }, Int{ 3 }, Int{ 4 }, Int{ 5 }) << "\n"; // prints 15
	std::cout << addInts() << "\n"; // prints 0
	std::cout << mulInts1(Int{ 1 }, Int{ 2 }, Int{ 3 }, Int{ 4 }, Int{ 5 }) << "\n"; // prints 120
	std::cout << mulInts2(Int{ 1 }, Int{ 2 }, Int{ 3 }, Int{ 4 }, Int{ 5 }) << "\n"; // prints 120
	std::cout << mulInts1() << "\n"; // prints 1
	std::cout << mulInts2() << "\n"; // prints 1
	//foldSumRight(); //Error
	std::cout << addall();
}


/*===================================================================================================================*/

template<typename T, typename... Args>
void push_back_vec(std::vector<T>& v, Args&&... args)
{
	(v.push_back(args), ...);
}

template< typename... Args>
void doit(Args&&... args)
{
	((std::cout << args << ','), ...);
}

/*It is a common operation to need to perform a particular function over each element in a parameter pack.*/
void fold_over_comma() {
	std::vector<int> v;
	push_back_vec(v, 1, 2, 3, 4, 5);

	for (auto& element : v) {
		std::cout << element << ", ";
	}

	doit("One", 2.2, 3.3F, 4, 5);
}

int main()
{
	//variadic_template_basics();
	//variadic_size_of_demo();
	//compile_time_if_demo();
	//constexpr_if();
	// variadic_expression();
	//variadic_indices();
	//fold_expr_basic();
	//binary_fold();
	fold_over_comma();
}