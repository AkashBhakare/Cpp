// EnumTypeScoped.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <typeinfo>


void enumBasics() {
	// "enum class" defines this as a scoped enumeration instead of a standard enumeration
	enum class Color
	{
		red, // red is inside the scope of Color
		blue
	};

	enum class Fruit
	{
		banana, // banana is inside the scope of Fruit
		apple
	};

	// note: red is not directly accessible any more, we have to use Color::red
	Color color1{ Color::red };
	// note: banana is not directly accessible any more, we have to use Fruit::banana
	Fruit fruit1{ Fruit::banana };

	// compile error here, as the compiler doesn't know how to compare different types Color and Fruit
	/*if (color1 == fruit1)
		std::cout << "color and fruit are equal\n";
	else
		std::cout << "color and fruit are not equal\n";*/


		/*you can still compare enumerators from within the same enum class*/

	Color color2{ Color::red };
	/* comparing two enum type variables*/
	if (color1 == color2)
		std::cout << "Colors are same\n";
	else
		std::cout << "Colors are different\n";

	/*Comparing enum varaible with enumerator of its own type*/
	if (color2 == Color::red) // this is okay
		std::cout << "The color is red!\n";
	else if (color2 == Color::blue)
		std::cout << "The color is blue!\n";
	return;

}

/*
* you have to use a scope qualifier to access the enumerator (e.g. Color::red).
  This helps keep name pollution and the potential for name conflicts down.
*/
void enumScope() {

	enum class TrafficLight
	{
		GREEN,
		YELLOW,
		RED
	};

	enum class Colors
	{
		CYAN,
		PINK,
		MAGENTA,
		YELLOW
	};

	//Colors acolor{ YELLOW };

	//have to use a scope qualifier to access the enumerator
	Colors acolor{ Colors::YELLOW };
	TrafficLight light{ TrafficLight::YELLOW };

}

/*
* the compiler will no longer implicitly convert enumerator values to integers.
  This is mostly a good thing. However, there are occasionally cases where it
  is useful to be able to do so. In these cases, you can explicitly convert an
  enum class enumerator to an integer by using a static_cast to int:
*/
void enumConversion() {
	enum class Color
	{
		red,
		blue
	};

	//  std::cout << "COLOR RED    : " << red << std::endl;
   //	std::cout << "COLOR RED    : " << Color::red << std::endl;
	std::cout << "COLOR red    : " << static_cast<int>(Color::red) << std::endl;
	std::cout << "COLOR blue   : " << static_cast<int>(Color::blue) << std::endl;

	Color acolor{ Color::blue };
	//std::cout << acolor; // won't work, because there's no implicit conversion to int
	std::cout << "COLOR acolor : " << static_cast<int>(acolor); // will print 1
	return;
}

/*
* Being able to specify the underlying type allows simpler interoperability
  and guaranteed sizes of enumerations:
*/
void enumCompactRepresentation() {
	// by default, the underlying type is int
	enum class TrafficLight { red, yellow, green };
	std::cout << "Type :" << typeid(TrafficLight::green).name() << std::endl;
	std::cout << "Value :" << static_cast<int>(TrafficLight::yellow) << std::endl;
	std::cout << "TrafficLights Size :" << sizeof(TrafficLight) << std::endl;

	enum class Colors : std::int8_t { RED = 1, GREEN = 2, BLUE = 3 };
	std::cout << "Colors Size :" << sizeof(Colors) << std::endl;

	enum class Color : char { red, blue };  // compact representation
	std::cout << "Type :" << typeid(Color::red).name() << std::endl;
	std::cout << "Value :" << static_cast<int>(Color::blue) << std::endl;
	std::cout << "Color Size :" << sizeof(Color) << std::endl;

	// now we can be specific
	enum FriendContact : unsigned long long {
		yash = 9876543217LL,
		geeta = 98777766543LL
	};
	std::cout << "FriendContact Size :" << sizeof(FriendContact) << std::endl;

	/*enum EE : float {

	};*/

}


int main()
{
	//enumBasics();
	//enumScope();
	//enumConversion();
	enumCompactRepresentation();
	std::this_thread::sleep_for(std::chrono::seconds(10));
}