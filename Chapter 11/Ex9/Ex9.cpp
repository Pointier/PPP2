// Ex9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"

void read()
{
	ifstream ifs{ "normal.txt" };
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);
	if (!ifs) error("can't open : ", "normal.txt");

	ofstream ofs_b{ "binary.txt",ios_base::binary };
	string word;
	while (ifs >> word)
	{
		ofs_b.write(as_bytes(word), sizeof(int));
	}
}

void read_binary()
{
	ifstream ifs_b{ "binary.txt",ios_base::binary };
	ifs_b.exceptions(ifs_b.exceptions() | ios_base::badbit);
	if (!ifs_b) error("can't open : ", "binary.txt");

	ofstream ofs{ "normal.txt" };
	string word;
	for (int i{}; !(ifs_b >> std::ws).eof();i++)
	{
		ifs_b.read(as_bytes(i), sizeof(int));
	}
	while (ifs_b >> word)
	{
		ofs << word;
	}
}

int main()
try{
	read_binary();
}

catch (exception & e)
{
	cerr << e.what();
}

catch (...)
{
	cerr << "Unknown expression";
}