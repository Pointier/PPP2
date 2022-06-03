// Quadra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../std_lib_facilities.h"

int main()
{
	//(-b + racine carré de->(b² - 4 * a * c) / 2 * a);
	double a{ 0 }, b{ 0 }, c{ 0 };
	double discriminant{ 0 };
	double result{ 0 };
	double x1, x2;
	
	
	std::cin >> a >> b >> c;
	
	
	discriminant = b * b - 4 * a * c;
	std::cout << discriminant << '\n';

	if (discriminant < 0) {
		std::cout << "No solutions." << std::endl;
	}
	else if (discriminant == 0) {
		result = -b / (2 * a);;
		std::cout << result << std::endl;
	}
	else if (discriminant > 0) {
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);
		std::cout << x1 << std::endl << x2 << std::endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
