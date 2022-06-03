// Drill2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

std::ostream& print_array(std::ostream& os, int* a, int n)
{
	for (int i{ 0 }; i < n; i++)
	{
		os << a[i] << ' ' << a << '\n';
	}

	return os;
}

int main()
{
	int n{ 7 };
	/*int* p1{ &n };
	//std::cout << "P1 value : " << p1 << " Int it points to value :" << *p1;

	//int* p2 = new int[7]{ 1,2,4,8,16,32,64, };
	
	int* p3 = p2;
	p2 = p1;
	p2 = p3;
	//std::cout << "P1 value : " << p1 << " Int it points to value :" << *p1;
	//print_array(std::cout, p2, 7);

	delete[] p1;
	delete[] p2;
	delete[] p3;
	
	int* p1 = new int[10]{ 1,2,4,8,16,32,64,128,256,512 };
	int* p2 = new int[10];

	for (int i{ 0 }; i < 10; i++)
	{
		p2[i] = p1[i];
	}
	print_array(std::cout, p1, 10);
	print_array(std::cout, p2, 10);
	*/
	std::cout << sizeof(bool) << ' ' << sizeof(int) << ' ' << sizeof(double);
	 


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
