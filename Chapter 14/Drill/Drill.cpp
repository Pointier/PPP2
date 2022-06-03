// Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class B1
{
public :
	virtual void vf() { std::cout << "B1::vf()\n"; }
	void f() { std::cout << "B1::f()\n"; }
	virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	void vf() { std::cout << "D1::vf()\n"; }
	void f() { std::cout << "D1::f()\n"; }
	void pvf() { std::cout << "D1::pvf()\n"; }
};

class D2 : public D1
{
public:
	void pvf() { std::cout << "D2::pvf()\n"; }
};

class B2
{
public :
	virtual void pvf() = 0;
};

class D21 : public B2
{
public :
	void pvf() { std::cout << s << '\n'; }


private :
	std::string s{"lol"};
};

class D22 : public B2
{
public:
	void pvf() { std::cout << i << '\n'; }


private:
	int i{5};
};

void f(B2& b)
{
	b.pvf();
}

int main()
{
	/*
	D1 d;

	d.vf();
	d.f();
	d.pvf();

	B1& r{ d };

	r.vf();
	r.f();
	r.pvf();

	D2 dd;

	dd.vf();
	dd.f();
	dd.pvf();
	*/

	D21 d;

	D22 dd;

	f(d);
	f(dd);


}
