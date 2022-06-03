// Ex8.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>

double sum(const std::vector<double>& price, const std::vector<double>& weight)
{
	if (price.size() != weight.size()) throw std::runtime_error("Weight and size are not of the same size\n");

	double sum{ 0 };

	for (int i{ 0 }; i < price.size(); i++)
	{
		sum+=price[i] * weight[i];
	}
	return sum;	
}

int main() {
	try {

		std::vector<double> price{ 1,2,3 };
		std::vector<double> weight{ 1,2,3 };
		double tot{ 0 };
		tot=sum(price, weight);
		std::cout << tot;

	}

	catch (std::exception& s)
	{
		std::cerr << s.what() << std::endl;
	}
}