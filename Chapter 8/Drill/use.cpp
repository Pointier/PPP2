#include <iostream>
#include "my.h"
int foo{ 7 };
namespace X {
	int var;
	void print() {
		std::cout << var;
	}
}

namespace Y {
	int var;
	void print() {
		std::cout << var;
	}
}

namespace Z {
	int var;
	void print() {
		std::cout << var;
	}
}

int main() 
{
	//print_foo();
	//print(99);

	/*int x = 7;
	int y = 9;
	swap_v (x, y); // replace ? by v, r, or cr
	swap_v (7, 9);
	print(x);
	print(y);*/

	/*const int cx = 7;
	const int cy = 9;
	swap_cr (cx, cy);
	swap_cr (7.7, 9.9);*/

	/*int dx = 7.7;
	int dy = 9.9;
	swap_r (dx, dy);
	print(dx);
	print(dy);*/

	X::var = 7;
	X::print(); // print X’s var
	using namespace Y;
	var = 9;
	print(); // print Y’s var
	{ using Z::var;
	using Z::print;
	var = 11;
	print(); // print Z’s var
	}
	print(); // print Y’s var
	X::print(); // print X’s var
	
}