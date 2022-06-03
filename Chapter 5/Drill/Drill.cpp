// Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()
try {

	//cout << "1 : Success!\n";
	//cout << "2 : Success!\n";
	//cout << "3 : Success" << "!\n";
	//cout << "4 : Success!" << '\n';
	//int res = 7; vector<int> v(10); v[5] = res; cout << "5 : Success!\n";
	//vector<int> v(10); v[5] = 7; if (v[5] == 7) cout << "6 : Success!\n";
	//if (true)cout << "7 : Success!\n"; else cout << "Fail!\n";
	//bool c = false; if (!c) cout << "8 : Success!\n"; else cout << "Fail!\n";
	//string s = "ape"; bool c = "fool" > s; if (c) cout << "9 : Success!\n";
	//string s = "ape"; if (s != "fool") cout << "10 : Success!\n";
	//string s = "ape"; if (s != "fool") cout << "11 : Success!\n";
	//string s = "ape"; if ("fool") cout <<"12 : Success!\n";
	//vector<char> v(1); for (int i = 0; i < v.size(); ++i) cout << "13 : Success!\n";
	//vector<char> v(5); for (int i = 4; i < v.size(); ++i) cout << "14 : Success!\n";
	//string s = "15 : Success!\n"; for (int i = 0; i < 15; ++i) cout << s[i];
	//if (true)  cout << "16 : Success!\n"; else cout << "Fail!\n";
	//int x = 2000; int c = x; if (c == 2000) cout << "17 : Success!\n";
	//string s = "18 : Success!\n"; for (int i = 0; i < 15; ++i) cout << s[i];
	//vector<int> v(1); for (int i = 0; i <= v.size(); ++i) cout << "19 : Success!\n";
	//int i = 0; int j = 9; while (i < 10) ++i; if (j < i) cout << "20 : Success!\n";
	//int x = 2; double d = 5 / (x / 2); if (d == 2 * (x + 0.5)) cout << "21 : Success!\n";
	//vector<string> s = { "22 : Success!\n" }; for (int i=0; i <1 ; ++i)cout << s[i];
	//int i = 0; while (i < 10) ++i; if (i) cout <<"23 : Success!\n";
	//int x = 4; double d = 5.0 / (x - 2); if (d ==2 + 0.5) cout << "24 : Success!\n";
	cout << "25 : Success!\n";
	

	keep_window_open();
	return 0;


}
catch (exception & e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
		keep_window_open();
		return 2;
}
