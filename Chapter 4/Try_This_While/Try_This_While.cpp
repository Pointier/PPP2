// Try_This_While.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	
	int unicode_val = 'a';
	char lettre = { 'a' };
		for (int i{ 0 }; i< 26;++i)
		{
			lettre = unicode_val + i;

			std::cout << lettre <<'\t' << unicode_val +i <<'\n';
			
			
		}
}

