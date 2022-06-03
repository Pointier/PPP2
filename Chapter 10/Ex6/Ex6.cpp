// Ex6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"
class Roman_int {
	public:
		string r;

	void as_int(const string&);
 };

int value(const char& c)
{
	int v{ 0 };
	switch (c) {
	case 'I':
		v = 1;
		break;
	case 'V':
		v = 5;
		break;
	case 'X':
		v = 10;
		break;
	case 'L':
		v = 50;
		break;
	case 'C':
		v = 100;
		break;
	case 'D':
		v = 500;
		break;
	case 'M':
		v = 1000;
		break;
	default:
		error("Wrong letter");
	}
	return v;

}

void Roman_int::as_int(const string& r)
{
	vector<int> stock;

	for (char c : r)
	{
		int a{};
		a = value(c);
		stock.push_back(a);
	}
	int number{};
	if (stock.size() == 1)
	{
		cout << stock[0];
		return;
	}
	for (int i{0}; i < stock.size() - 2; i++)
	{
		number += stock[i];
	 }

	int i=static_cast<int>(stock.size());

	if (stock.size() > 2) i = i- 2;

	if (stock[i] >= stock[i + 1]) number += stock[i] + stock[i + 1];
	else number += stock[i + 1] - stock[i];

	cout << number;
	
}

int main()
try{
	Roman_int r;
	string s;
	while (cin >> s) {
		if (s == "Q") break;
		r.as_int(s);

	}
	return 0;
}

catch (exception & e) {
	cerr << e.what();
}