// Ex7.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>


int main()
{
	char* c[]{ new char };
	while (std::cin >> *c)
	{
		int i{ 0 };
		char a{ ' ' };
		a = *c[i];
		if (a == '!') break;
		
		std::cout << *c;
		i++;
	}
   
}


