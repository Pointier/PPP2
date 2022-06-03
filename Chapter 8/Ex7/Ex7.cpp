// Ex7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>  

void print(std::string label, const std::vector<std::string>& a)
{
	std::cout << label << '\n';

	for (int i{ 0 }; i < a.size(); ++i) {
		if (i % 8 == 0) std::cout << '\n';
		std::cout << a[i];
		if (i < a.size() - 1) std::cout << ',';
	}
	std::cout << '\n';
}

void print_pair(std::string label, const std::vector<std::string>& a, const std::vector<int>& b)
{
	std::cout << label << '\n';

	for (int i{ 0 }; i < a.size(); ++i) {
		if (i % 8 == 0) std::cout << '\n';
		std::cout << a[i] << ' ' << b[i];
		if (i < a.size() - 1) std::cout << ',';
	}
	std::cout << '\n';
}

void stock_ages(std::vector<int>& ages)
{
	int size{ 5 };
	int age{ 0 };
	for (int i{0}; i<size; i++)
	{
		std::cin >> age;
		ages.push_back(age);

	}

}

std::vector<int> sort_ages(const std::vector<std::string>& names,const std::vector<std::string>& sorted_names, const std::vector<int>& ages)
{
	std::vector<int> sorted_ages;
	for (int i{0}; i<sorted_names.size();i++)
	{
		for (int z{ 0 }; z < names.size(); z++)
		{
			if (sorted_names[i] == names[z]) sorted_ages.push_back(ages[z]);
		}
	 }
	return sorted_ages;
}

int main()
{
	std::vector<std::string> names{ "Sarah","Paul","Behdis","Funk","Lucette" };
	print("Noms : ", names);
	std::cout << "Enther the age of these people in the order: \n";
	std::vector<int> ages;
	stock_ages(ages);
	
	print_pair("Noms et ages : ", names, ages);
	std::vector<std::string> names_2 = names;

	std::sort(names.begin(), names.end());

	std::vector<int> sorted_ages;
	sorted_ages = sort_ages(names_2, names, ages);

	print_pair("Nom et ages triés : ", names, sorted_ages);
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
