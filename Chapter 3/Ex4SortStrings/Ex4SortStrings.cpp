// Ex4SortStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	
		std::cout << "Please enter 3 string values to sort:\n";
		std::string val1;
		std::string val2;
		std::string val3;
		std::string greatest;
		std::string middlest;
		std::string smallest;
		std::cin >> val1 >> val2 >> val3;

		if (val1 < val2 && val1 < val3) {

			smallest = val1;

			if (val2 < val3) {
				middlest = val2;
				greatest = val3;
			}
			else {
				middlest = val3;
				greatest = val2;
			}

		}
		else if (val2 < val3) {

			smallest = val2;

			if (val1 < val3) {
				middlest = val1;
				greatest = val3;
			}
			else {
				middlest = val3;
				greatest = val1;
			}

		}
		else {

			smallest = val3;

			if (val1 < val2) {
				middlest = val1;
				greatest = val2;
			}
			else {
				middlest = val2;
				greatest = val3;

			}
		}
				std::cout << smallest << " " << middlest << " " << greatest << '\n';
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
