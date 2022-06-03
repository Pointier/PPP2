// Ex11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

class Link {
	
public:
	
	string value;
	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
		: value{ v }, prev{ p }, succ{ s } { }
	Link* insert(Link* n); // insert n before this object
	Link* add(Link* n); // insert n after this object
	Link* erase(Link* p); // remove this object from list
	Link* find(Link* p, const string& s); // find s in list
	//const Link* find(Link* p, const string& s) const; // find s in const list (see §18.5.1)
	Link* advance(Link* p, int n) const; // move n positions in list
	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n) // insert n before this object; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n-> succ = this; // this object comes after n
	if (prev) prev-> succ = n;
	n-> prev = prev; // this object’s predecessor becomes n’s predecessor
	prev = n; // n becomes this object’s predecessor
	return n;
}

Link* Link::add(Link* n) // insert n after p; return n
{
	// much like insert (see exercise 11)
}
Link* Link::erase(Link* p) // remove *p from list; return p’s successor
{
	if (p == nullptr) return nullptr;
	if (p-> succ) p-> succ-> prev = p-> prev;
	if (p-> prev) p-> prev-> succ = p-> succ;
	return p-> succ;
}
 Link* Link::find(Link* p, const string& s)  // find s in list;
// return nullptr for “not found”
{
	while (p) {
		if (p-> value == s) return p;
		p = p-> succ;
	}
	return nullptr;
}
Link* Link::advance(Link* p, int n) const // move n positions in list
// return nullptr for “not found”
// positive n moves forward, negative backward
{
	if (p == nullptr) return nullptr;
	if (0 < n) {
		while (n--) {
			if (p-> succ == nullptr) return nullptr;
			p = p-> succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p-> prev == nullptr) return nullptr;
			p = p-> prev;
		}
	}
	return p;
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p) {
		cout << p-> value;
		if (p = p-> next()) cout << ", ";
	}
	cout << " }";
}


int main()
{
    std::cout << "Hello World!\n";
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
