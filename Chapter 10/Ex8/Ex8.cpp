// Ex8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"

vector<string> read_file(string n)
{
	ifstream ifs{ n };
	if (!ifs) error("can't open the file ", n);
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);

	vector<string> s;
	while (ifs >> n)
	{
		s.push_back(n);
	}
	return s;
}

void concatenate(const vector<string>& n, const vector<string>& s)
{
	ofstream ofs{ "concatened.txt" };
	if (!ofs) error("can't open the file ", "concatened.txt");
	ofs.exceptions(ofs.exceptions() | ios_base::badbit);

	for (string i : n)
	{
		ofs << i << " ";
	}
	for (string i : s)
	{
		ofs << i << " ";
	}
}

int main()
{
	string filename1;
	string filename2;

	cin >> filename1 >> filename2;

	vector<string> content1;	
	content1=read_file(filename1);
	vector<string> content2;
	content2=read_file(filename2);

	concatenate(content1, content2);
	return 0;
}

