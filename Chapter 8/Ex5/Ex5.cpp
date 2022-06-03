// Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void print(std::string label, const std::vector<int>& a)
{
	std::cout << label << '\n';

	for (int i{ 0 }; i < a.size(); ++i) {
		if (i % 8 == 0) std::cout << '\n';
		std::cout << a[i];
		if (i < a.size() - 1) std::cout << ',';
	}
	std::cout << '\n';
}

void fibonacci(const int x, const int y, std::vector<int>& v, int n)
{
	n = n - 2;
	v.push_back(x);
	v.push_back(y);
	for (int i{ 0 }; i < n; ++i) {
		int sum{ 0 };
		sum = v[i] + v[i + 1];
		v.push_back(sum);
	}
}

std::vector<int> swap(const std::vector<int> v)
{
	std::vector<int> v_swap;
	v_swap = v;
	int  n_swap{ 0 };
	n_swap = v.size() / 2;
	if (v.size() % 2 == 0) n_swap=n_swap-1; // if number is pair
		
	for (int i{ 0 }; i <= n_swap; i++)
	{
		std::swap(v_swap[i], v_swap[v_swap.size() - 1 - i]);
	}
	return v_swap;
}

void swap_r( std::vector<int>& v)
{
	
	
	int  n_swap{ 0 };
	n_swap = v.size() / 2;
	if (v.size() % 2 == 0) n_swap = n_swap - 1; // if number is pair

	for (int i{ 0 }; i <= n_swap; i++)
	{
		std::swap(v[i], v[v.size() - 1 - i]);
	}

}

int main()
{
	std::vector<int> essai{ 1, 2, 3, 4,5,6};
	std::vector<int> copie;
	//copie = swap(essai);
	swap_r(essai);
	print("essai",essai);
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
