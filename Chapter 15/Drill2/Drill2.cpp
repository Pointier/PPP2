// Drill2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

struct Person
{
	Person(std::string n, int a);
		

	std::string r_name() const { return name; }
	int r_age() const { return age; }

private:
	std::string name;
	int age;
};

Person::Person(std::string n, int a)
:name{ n }, age{ a }
{
	if (age > 150 || age < 0) throw (" Wrong age");

	std::string punct{ ";:'[]*&^$#@!" };
	for (char c : name)
	{
		for (char a : punct)
		{
			if (c == a || c == '"') throw ("Wrong char");
		}
	}
}

std::istream& operator>>(std::istream& is, Person& p)
{
	std::string n;
	int a{};
	is >> n >> a;
	p = Person{ n,a };
	return is;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
	return os << p.r_name() << " " << p.r_age() << std::endl ;
}

int main()
try{
	std::vector<Person> a;
	Person p("Goofy", 63);
	std::cout << p;
	for (int i{}; i < 5; i++)
	{
		std::cin >> p;
		a.push_back(p);
	}
	for (int i{}; i < a.size(); i++)
	{
		std::cout << a[i];
	}
	
}

catch (std::exception & e)
{
	std::cerr << e.what();
}

catch (...)
{
	std::cerr << "Unkwown exception\n";
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
