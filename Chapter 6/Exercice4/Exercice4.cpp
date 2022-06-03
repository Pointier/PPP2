// Exercice4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h";

class Name_value {
public:
	string name{ "" };
	int value{ 0 };

	Name_value(string na, int va)
		:name(na), value(va) {}
};


int main()
{

	//Name_value cont;
	string name;
	int value;
	vector<Name_value> stock;
	cout << "Enter name and age like 'Name 14' enter NoName 0 to stop\n";

	while (true) {
		bool lol{false};
		cin >> name >> value;
		if (name == "NoName" && value == 0)
			break;
		for (int i = 0; i < stock.size(); ++i) {
			if (name == stock[i].name)
				lol = true;
		}
		if (lol)
			cout << "Name already entered";
		else
		stock.push_back(Name_value(name,value));
		lol = false;
		
	}
	for (int i = 0; i < stock.size(); ++i) {
		cout << "Result : \n";
		cout << stock[i].name <<' ' << stock[i].value <<'\n';
	}



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
