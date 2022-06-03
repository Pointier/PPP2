// Exercice10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"

int factorial(int x) {
	if (x == 0)
		return 1;
	else
	for (int i{ x-1 }; i > 1; --i) {
		x *= i;
	}
	return x;
}

int permutation(int a, int b) {
	int result{ 0 };
	result = factorial(a) / factorial(a - b);
	return result;
}

int combination(int a, int b) {
	int result{ permutation(a,b) };
	result /= factorial(b);
	return result;

}

int main()
try {
	int input1{ -1 };
	int input2{ -1 };
	int result{ -1 };

	cout << "Enter two integers, to calculate a combination or permutation,"
		"The first number must be higher than the second\n";
		
	cin >> input1 >>input2;

	if (input2 > input1) error("The second input must be smaller than the first");
	cout << "Enter 'p' to a permutation\n"
		"Enter 'c' to a combination\n";
	char choice{' '};
	
	cin >> choice;
	if ((choice!='p') & (choice != 'c'))  error("Didn't enter 'c' or 'p'");
	if (choice=='p')
		result = permutation(input1, input2);
	else if (choice=='c')
		result = combination(input1, input2);

	

	cout<<"The result is :" << result;
}

catch (exception & e) {
	cerr << "Error : " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Oops : Unknown exception!\n";
	return 2;
}
