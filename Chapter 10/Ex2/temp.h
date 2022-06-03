#include <iostream>;
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <array>
#include <regex>
#include<random>
#include<stdexcept>

using namespace std;




void seed_randint(int s);

inline int randint(int min, int max);



inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s + s2);
}


struct Reading {

	int hour;
	double temp;
	char t;

};




Reading rand_reading();
void write_file(int n);
vector<Reading> read_file();
void mean(const vector<Reading>& r);
void median(const vector<Reading>& r);

