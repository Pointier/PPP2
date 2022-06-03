// Ex2_median.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm> 


int main()
{
	std::vector<double> values{ 1,2,3,4,5 };
	int remainder{0};
	remainder = values.size();
	std::cout << remainder % 2<<'\n';
	std::sort(values.begin(), values.end());

	if (remainder % 2 == 1) {
		std::cout << "bb\n";
		std::cout << values[values.size()/2];
	}

	else {
		double	x1{ values[values.size() / 2 ] };
		double	x2{ values[values.size() / 2 - 1] };
		std::cout << "aa\n";
		std::cout << (x1 + x2) / 2;
		
	}
}
