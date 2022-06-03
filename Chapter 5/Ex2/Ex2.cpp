// Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

double ctok(double c)
// take celsius, cannot go lower than -273.15
{
	const double c_min = -273.15; //minimum value for c
	if (c < c_min) error("Celsius cannot go under -273.15°\n");
	const double c0 = 273.15; // temperature in kelvin for c=0°
	double k = c + c0;
	return  k;
}

int main()
try {
	

	double c = 0;	
	cin >> c;
	
	double k = ctok(c);
	cout << k << '\n';
	
	
}

catch (exception & e)
{
	cerr << "error: " << e.what();
	return 1;
	
}
