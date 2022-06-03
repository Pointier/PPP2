// Ex1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int fac(int n) { return n > 1 ? n * fac(n-1) : 1; } // factorial n!

int fac_it(int n) // factorial(n); n!
{
	int r = 1;
	while (n > 1) {
		r *= n;
		--n;
	}
	return r;
}

int main()
{
	for (int i{ 0 }; i < 21; i++)
	{
		std::cout <<i <<"Recu :" << fac(i)
			<<"\t" <<"Ite :" <<fac_it(i)<<'\n';
	}
}
