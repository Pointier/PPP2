// Ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// A E I O U Y

#include "../../std_lib_facilities.h"

bool isvowels(char c)
{
	string vowels{ "AEIOUYaeiouy" };
	for (char w : vowels)
	{
		if (w == c) return true;		
	}
	return false;
}


void del_vo(string n)
{
	ifstream ifs{ n };
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);
	if (!ifs) error("can't open : ", n);

	vector<string> v_w;
	string w;
	

	while (ifs >> w)
	{

		string nv;
		for (char c : w)
		{
			if (!isvowels(c)) nv+=c;
		}
		v_w.push_back(nv);

	}	


	ofstream ofs{ "novowels.txt" };
	ofs.exceptions(ofs.exceptions() | ios_base::failbit);
	for (string s : v_w)
	{
		ofs << s << " ";
	}

}

int main()
{
	string filename{"try.txt"};
	del_vo(filename);

}

