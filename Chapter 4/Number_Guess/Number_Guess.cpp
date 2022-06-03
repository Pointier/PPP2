// Number_Guess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	
	int x{ 50 };
	int smallest{ 1 };
	int largest{ 100 };
	char input{ ' ' };
	int guess{ 0 };


	std::cout << "Think of a number (integer) between 1 and 100 \n";
	std::cout << "Computer will ask question, answer by 'y' for yes and by 'n' for no \n";
	std::cout << "Enter '|' to end \n";


	for (int i{ 0 }; i < 7; ++i)
	{
		std::cout << "Is this number higher than " << x << " ? \n";

		std::cin >> input;

		if (input == '|')
			return 0;

		else  {
			if (input == 'y') {
				
				smallest = x;				
				x = (smallest + largest) / 2;
					
				}
			else if(input == 'n') {
				
				largest = x;
				x = (smallest + largest) / 2;

				}
			}

			

		if (i == 6 && (input == 'y' )) {
			guess =largest;
			std::cout << "The number you were thinking is " << guess << "?\n";
		}
		
		else if (i == 6 && (input == 'n')) {
			guess = largest;
			std::cout << "The number you were thinking is " << guess << "?\n";
		}
		

	}
}
		
	
	

		





	

