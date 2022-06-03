// Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"
#include "my.h"

void print_foo() 
{
	cout << foo << endl;
}

void print(int i) 
{
	cout << i;
}

 void swap_v(int a, int b) 
{

	int temp; 
	temp = a, 
	a = b; 
	b = temp;
	
}

 void swap_r(int& a, int& b)
 {
	 int temp; 
	 temp = a, 
	 a = b; 
	 b = temp;
 }
 /*void swap_cr(const int& a, const int& b)
 {
	 int temp;
	 temp = a,
	 a = b;
	 b = temp;
 }*/