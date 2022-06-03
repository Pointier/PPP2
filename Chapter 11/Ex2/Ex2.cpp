// Ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"
struct info {
	string word;
	int line;
};

void n_words(string n, string w)
{
	ifstream ifs{ n };
	ifs.exceptions(ifs.exceptions() | ios_base::badbit);
	if (!ifs) error("can't open file ", n);
	string line;
	
	vector<string> v_line;
	while (getline(ifs, line))
	{
		v_line.push_back(line);
	}



	
	vector<info> infos;
	info in;
	string word;
	int i_line{ 1 };
	for (string s : v_line)
	{
		for (char c : s)
		{
			if (isspace(c) || ispunct(c))
			{
				in.word = word;
				in.line = i_line;
				infos.push_back(in);
				word = "";
			}
			if (isalpha(c))
			{
				word += c;
			}
		}
		i_line += 1;
	}
	for (int i{}; i < infos.size();i++)
	{
		string ss{ infos[i].word };
		if (ss == w) cout << "word find at line : " << infos[i].line<< '\n';

	}
}



int main()
{
	string filename{ "word.txt" };
	string word{"lol"};
	n_words(filename, word);
    
}
