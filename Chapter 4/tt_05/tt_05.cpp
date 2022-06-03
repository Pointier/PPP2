// tt_05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int archaic_square(int v) {
	int total = 0;

	for (int i = 0; i < v; ++i) {
		total += v;
	}

	return total;
}

int main()
{
	for (int i = 0; i < 100; ++i) {
		std::cout << i << '\t' << archaic_square(i) << '\n';
	}
}