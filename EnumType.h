#include <iostream>
#include <thread>
#include <chrono>
#include "EnumType.h"
#include "d3dApp.h"
#include <stream>

void enumBasic() {

	enum TrafficLight
	{
		GREEN,
		YELLOW,
		RED
	};

	TrafficLight trafficlight = GREEN;

	// Checking some stuff
	if (trafficlight == TrafficLight::GREEN)
		std::cout << "Traffic light is green! You may proceed" << std::endl;
	if (trafficlight == TrafficLight::YELLOW)
		std::cout << "Traffic light is yellow! Go slow" << std::endl;
	if (trafficlight == TrafficLight::RED)
		std::cout << "Traffic light is red! Please Stop" << std::endl;

}

void enumScope() {
	//conventional enums export their enumerators to the surrounding scope, causing name clashes.
	enum TrafficLight
	{
		GREEN,
		YELLOW = 5,
		RED
	};
	std::cout << "GREEN   : " << GREEN << std::endl;

	enum Colors
	{
		CYAN,
		PINK,
		MAGENTA,
		//YELLOW = 10
	};
	std::cout << "PINK    : " << PINK << std::endl;
	std::cout << "MAGENTA : " << MAGENTA << std::endl;
	//std::cout << "YELLOW  : " << Colors::YELLOW << std::endl;
	std::cout << "YELLOW  : " << TrafficLight::YELLOW << std::endl;
}

enum Color
{
	RED, // color red is placed in the same scope as Color
	BLUE
};

enum Fruit
{
	BANANA, // fruit banana is placed in the same scope as Fruit
	APPLE
};

int getFruitPrice(Fruit afruit) {
	if (afruit == APPLE)
		return 100;
	else
		if (afruit == BANANA)
			return 70;
}

void enumConversion() {
	/*conventional enums implicitly convert to int, causing errors when someone
	does not want an enumeration to act as an integer.*/

	//implicit conversion
	Color aColor{ RED }; // Color and RED can be accessed in the same scope (no prefix needed)
	Fruit aFruit{ BANANA }; // Fruit and BANANA can be accessed in the same scope (no prefix needed)

	if (aColor == aFruit) // The compiler will compare a and b as integers
		std::cout << "color and fruit are equal\n"; // and find they are equal!
	else
		std::cout << "color and fruit are not equal\n";

	std::cout << "color :" << aColor << std::endl;
	std::cout << "fruit :" << aFruit << std::endl;

	std::cout << "Price of Apple  : " << getFruitPrice(APPLE) << std::endl;

	//One enum type does not convert to a different enum type implicitly
	/*std::cout << "Price of BANANA : " << getFruitPrice(RED) << std::endl;
	std::cout << "Price of BANANA : " << getFruitPrice(1) << std::endl;*/

	//But unscoped enums can implicitly convert to integer values, 
	aFruit = APPLE;
	//aFruit = BANANA;
	if (aFruit == BANANA)
		std::cout << "I Love Bananaa!" << std::endl;
	else
		if (aFruit == 1)  //implicit conversion while comparing
			std::cout << "a Apple a Day.. Keep the doctor away" << std::endl;
}



void enumNeed()
{
	std::cout << "Std Code of my city : " << 84 << std::endl;
	constexpr unsigned HYDERABAD_STD_CODE{ 84 };
	std::cout << "Std Code of my city : " << HYDERABAD_STD_CODE << std::endl;
	static constexpr int AKURDI{ 411035 };
	static constexpr int CHINCHWAD{ 411018 };
	static constexpr int PUNE{ 411004 };
	//static constexpr int PUNE{ 22 };
	int pincode = AKURDI;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = CHINCHWAD;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = PUNE;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = -565656;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = HYDERABAD_STD_CODE;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
}

void enumDeclaration() {
	/*Create a type that can be assigned values only in the specified range*/
	enum PINCODE {  //Declaration of enum type
		AKURDI = 411035,
		NIGDI = 411044,
		BHOSARI = 411027,
		CHINCHWAD = 411018
	};

	PINCODE citycode; //defining a variable of enum type
	citycode = AKURDI;
	std::cout << "Pincode Code : " << citycode << std::endl;
	citycode = BHOSARI;
	std::cout << "Pincode Code : " << citycode << std::endl;
	/* CityCode can be assigned values specified in the enumeration only*/
	//citycode = NASIK;
	//citycode = 777777;
	return;
}

int main()
{
	// enumNeed();
	// enumDeclaration();
	// enumBasic();
	// enumScope();
	// enumConversion();
	std::this_thread::sleep_for(std::chrono::seconds(5));
}