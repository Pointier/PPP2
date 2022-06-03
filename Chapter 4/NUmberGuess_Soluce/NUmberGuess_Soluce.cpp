// NUmberGuess_Soluce.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


	int get_diff(int val1, int val2) {
		int diff;

		if (val1 > val2)
			diff = val1 - val2;
		else
			diff = val2 - val1;

		return diff;
	}

	int main()
	{
		int upper_boundary = 100;
		int lower_boundary = 1;
		int prev = upper_boundary;
		int cur = upper_boundary / 2;
		int diff = 0;
		int iterator = 0;

		char answer = ' ';

		bool guessed = false;

		std::cout << "Think of a number between 1 and 100.\n";

		while (iterator < 7 && guessed == false) {
			std::cout << "Is your number less than " << cur << "?(y/n)\n";
			std::cin >> answer;

			diff = get_diff(prev, cur);
			prev = cur;

			if (answer == 'y') {
				upper_boundary = cur;

				if (cur == lower_boundary + 1)
					guessed = true;
				else {
					if (diff > 1)
						cur -= diff / 2;
					else
						cur -= 1;
				}

			}
			else if (answer == 'n') {
				lower_boundary = cur - 1;

				if (cur == upper_boundary - 1)
					guessed = true;
				else {
					if (diff > 1)
						cur += diff / 2;
					else
						cur += 1;
				}
			}

			++iterator;
		}

		std::cout << "Is your number " << cur << "?\n";
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
