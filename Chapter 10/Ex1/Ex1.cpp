//Chapter 10, ex 1

#include "../../std_lib_facilities.h"

void sum()
{
	string filename{ "mydata.txt" };
	ifstream ifs{ filename };
	if (!ifs) error("can't open input file : ", filename);
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);
	int sum{};

	while (true) {
		
		int x{};
		ifs >> x;
		sum += x;
		if (ifs.eof()) break;
	}
	cout << sum;
}

int main()
try{
	sum();

}

catch (exception & e)
{
	cerr << e.what();
}

catch (...)
{
	cerr << "Unknown exception";
}