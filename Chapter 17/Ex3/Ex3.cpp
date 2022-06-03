// Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void to_lower(char* s)
{
	for (int i{ 0 }; s[i]; i++)
	{
		if (int(s[i]) >= 65 && int(s[i]) <= 95)
		{
			s[i] = int(s[i]+32);
		}
	}
	
	for (int i{ 0 }; s[i]; i++)
	{
		std::cout << s[i];
	}
}

int main()
{
	char c[] = "Hello World!";
	//char* c = new char[13]{ 'H','e','l','l','o',' ','W','o','r','l','d','!',0 };
	std::string s;
	//while (std::cin >> s && s != "quit")
	//	to_lower(&s[0]);
	to_lower(c);

	return 0;
}

