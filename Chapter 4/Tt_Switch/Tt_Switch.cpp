// Tt_Switch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	constexpr double yen_to_d{ 0.2 };
	constexpr double kroner_to_d{ 1.5 };
	constexpr double pounds_to_d{ 1 };

	double value{ 0 };

	char unit{ ' ' };

	std::cout << "Please enter a value followed by a unit (y, k, or p) : \n";
	std::cin >> value >> unit;

	switch (unit) {
	case 'y' : 
			std::cout << "Yen to dollar value is " << value * yen_to_d << '\n';
			break;
	case 'k' :
			std::cout << "Kroner to dollar value is " << value * kroner_to_d << '\n';
			break;
	case 'p' :
			std::cout << "Pounds to dollar value is " << value * pounds_to_d << '\n';
			break;
	default:
			std::cout << "Sorry, I don't know a unit called " << unit << '\n';
			break;
	}



}