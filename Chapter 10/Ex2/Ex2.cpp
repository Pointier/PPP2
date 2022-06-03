// Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "temp.h"



int main()
try{
	/*
	int numb_of_temp{ 50 };
	cout << "How many temperature you want to create ? \n";
	cin >> numb_of_temp;
	write_file(numb_of_temp);
	*/
	
	vector<Reading> r;
	r=read_file();
	mean(r);
	median(r);
	

}

catch (exception & e)
{
	cerr << e.what();
}

catch (...)
{
	cerr << "Unknown exception";
}