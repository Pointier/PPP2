// Ex4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

char* dup(const char* c)
{
	char* pc = new char{' '};
	for (int i{ 0 }; c[i]; i++)
	{
		
		pc[i] = c[i];
		pc[i + 1] = NULL;
	}
	
	return pc;
}

void print_array(char* c)
{
	for (int i{ 0 }; c[i]; i++)
		std::cout << c[i];
	std::cout << '\n';

}

int main()
{
	
	std::string c;
	while (std::cin >> c && c != "quit")
	{
		char* pc = dup(&c[0]);
		print_array(pc);
		
	}


}
