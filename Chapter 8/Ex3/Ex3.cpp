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

	return v_swap;
}

int main()
{
	/*std::cout << "Enter an x,y,n \n";
	int x{ 0 };
	std::cin >> x;
	int y{ 0 };
	std::cin >> y;
	int n{ 0 };
	std::cin >> n;
	
	std::vector<int> fibo_suit;
	fibonacci(x, y, fibo_suit, n);
	std::string label{ "lol" };
	print(label, fibo_suit);*/
	int a{ 5 };
	std::cout << a / 2;
	//std::cout << x << y << n << std::endl;

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
