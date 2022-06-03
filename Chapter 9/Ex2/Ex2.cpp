// Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"

class Name_pairs
{
public:
	Name_pairs(vector<string> n)
		:name{n}
	{};
	void read_names();
	void read_ages();
	void print();
	void sort_all();
	const vector<string>& get_name() const { return name; }
	const vector<double>& get_age() const { return age; }
	
private:
	vector<string> name;
	vector<double> age;
};

void Name_pairs::read_names()
{
	for (string s : name)
		cout << s << '\n';
}

void Name_pairs::read_ages()
{
	cout << "Enter the age of these people\n";

	for (int i{}; i < name.size(); i++)
	{
		double x{};
		cin >> x;
		age.push_back(x);
	}
}

void Name_pairs::print()
{
	for (int i{};i<name.size();i++)
	{
		cout << name[i] << " : " << age[i]
			<< '\n';
		if (i + 1 == name.size()) cout << '\n';
	}
}

void Name_pairs::sort_all()
{
	vector<string> name_save {name};
	vector<double> age_save{ age };
	
	sort(name);

	for (int i{}; i<name.size();i++)
	{
		for (int a{};a<name.size();a++)
		{
			if (name_save[i] == name[a])
				age[a] = age_save[i];
		}
	}


}

bool operator==(const Name_pairs& a, const Name_pairs& b)
{
	if (a.get_name().size() != b.get_name().size() || a.get_age().size() != b.get_age().size())
		return false;
	bool equal = true;
	for (int i = 0; i < a.get_name().size(); ++i) {
		if (a.get_name()[i] != b.get_name()[i])
			return false;
	}
	for (int i = 0; i < a.get_age().size(); ++i) {
		if (a.get_age()[i] != b.get_age()[i])
			return false;
	}
	return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a == b);
}

ostream& operator<<(ostream& os, const Name_pairs& n)
{
	vector<string> name;
	vector<double> age;
	age = n.get_age();
	name = n.get_name();
	for (int i{}; i < name.size(); i++)
		 os << name[i] << " : " << age[i] <<'\n';

	return os;
}

int main()
{
	vector<string> name_list{ "Andreah", "Bibo","Palme" ,"Gaston" };
	Name_pairs nom(name_list);
	
	Name_pairs nom2(name_list);
	nom.read_names();
	nom.read_ages();
	cout << nom;
	//nom.sort_all();
	cout << nom;
	nom2.read_ages();
	if (nom == nom2) cout << "Identical!\n";
	if (nom != nom2) cout << "Not identical";


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
