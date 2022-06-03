// Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"

int main()
{
	/*
	int birth_year{ 1996 };

	cout <<showbase
		<< dec << birth_year << "\t(decimal)\n"
		<< hex << birth_year << "\t(hexadecimal)\n"
		<< oct << birth_year << "\t(octal)\n";

	int age{ 24 };

	cout << showbase
		<< dec << age << "\t(decimal)\n"
		<< hex << age << "\t(hexadecimal)\n"
		<< oct << age << "\t(octal)\n";
		*/

	/*
	int a, b, c, d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
	*/

	double d{ 1234567.89 };
	cout << defaultfloat << d << '\t' << fixed << d << '\t' << scientific << d;

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
