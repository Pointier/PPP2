// Ex4_Value.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	std::cout << "Enter 2 integers please : ";
	double val1{ 0 };
	double val2{ 0 };
	std::cin >> val1 >>val2;

	if (val1 < val2)
		std::cout << val2 << " is larger than " << val1 << '\n';
	if (val1 > val2)
		std::cout << val1 << " is larger than " << val2 << '\n';

	std::cout << val1 << '+' << val2 << " is equal " << val1 + val2 << '\n';
	std::cout << val1 << '-' << val2 << " is equal " << val1 - val2 << '\n';
	std::cout << val1 << '*' << val2 << " is equal " << val1 * val2 << '\n';
	std::cout << val1 << '/' << val2 << " is equal " << val1 / val2 << '\n';

}

