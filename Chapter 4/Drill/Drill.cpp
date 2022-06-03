// Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	double temp_a{ 0 };
	double temp_b{ 0 };
	double x1{ 0 };
	double x2{ 0 };

	while (std::cin >> temp_a >> temp_b )
	{
		if (temp_a == '|') {
			return 0;
		}
		else {
			if (temp_a == temp_b) {
				std::cout << "The numbers are equal " << '\n';
			}
			else if (temp_a > temp_b) {
				std::cout << "The smaller value is " << temp_b << '\n';
				std::cout << "The larger value is " << temp_a << '\n';
				x1 = temp_a;
				x2 = temp_b;
			}
			else {
				std::cout << "The smaller value is " << temp_a << '\n';
				std::cout << "The larger value is " << temp_b << '\n';		
				x1 = temp_b;
				x2 = temp_a;
			}
					
		}
		double result{ x1 / x2 };
		if (result < 1.02) {
			std::cout << "The numbers are almost equal\n";
		}
		std::cout << result <<'\n';
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
