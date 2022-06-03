// Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <vector>

std::ostream& print_array(std::ostream& os, int* a,int n)
{
	 for (int i{ 0 }; i < n; i++)
	 {
		 os << a[i] << '\n';
	 }

	 return os;
}

std::ostream& print_vector(std::ostream& os, std::vector<int>& a)
{
	for (int i : a)
	{
		os << i << '\n';
	}

	return os;
}

int main()
{
	int* p = new int[11]{0,1,2,3,4,5,6,7,8,9,10};

	print_array(std::cout,p,11);
	delete[] p;

	std::vector<int> pp{1,2,3,4,5,6,7,8,9,10};
	print_vector(std::cout, pp);

	return 0;
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
