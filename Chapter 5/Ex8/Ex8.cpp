// Ex8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()

try {
	int sum_value{ 0 }; // number of value to sum
	double sum{ 0 };
	vector<double> stock{};
	vector<double> diff{};

	cout << "Please enter the number of value you want to sum : \n";
	cin >> sum_value;
	if (sum_value <= 1) 
		error("Number need to be higher than 1 to sum\n");

	cout <<"Please enter some double (press '|' to stop :\n";
	for (int x; cin >> x;) {
		stock.push_back(x);
	}
	if (stock.size() < sum_value) 
		error("You don't have enter enough value to sum the value you entered before");

	for (int i{ 0 }; i < sum_value; ++i) {
		sum += stock[i];
	}
	cout << "The sum of the first " << sum_value << " numbers ( ";
	for (int i{ 0 }; i < sum_value; ++i) 
		cout << stock[i] <<' ';
	cout << " ) is "<< sum << '\n';

	cout << "Difference between adjacent value is :\n";
	for (int i{ 1 }; i < stock.size(); ++i) {
		diff.push_back(stock[i] - stock[i - 1]);
	}
	for (int i{ 0 }; i < diff.size(); ++i)
		cout << diff[i] << '\n';
}

catch (exception & e){
	cerr << "error : " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Oops : unknown exception!\n";
	return 2;
}