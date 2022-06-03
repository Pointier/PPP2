// Drill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"

struct Point
{
	
	int x{0};
	int y{0};
};

void print_vec_point(const vector<Point>& p)
{
	for (int i{ 0 }; i < p.size(); i++) {
		cout << "x : " << p[i].x
			 << " y : "  << p[i].y << '\n';
	}
}

void write_file(const vector<Point>& p)
{
	string oname;
	cout << "Please enter name of output file: ";
	cin >> oname;
	ofstream ost{ oname };
	ost.exceptions(ost.exceptions() | ios_base::badbit);

	if (!ost) error("can't open output file", oname);

	for (int i{ 0 }; i < p.size(); i++)
	{
		ost << p[i].x <<' '
			<< p[i].y;
		if (i + 1 != p.size()) ost << '\n';
	}
}

void read_file(vector<Point>& p)
{
	string iname;
	cout << "Please enter name of the input file : ";
	cin >> iname;
	ifstream ist{ iname };
	ist.exceptions(ist.exceptions() | ios_base::badbit);
	if (!ist) error("can't open input file ", iname);

	while (true) {
		
		int x{ 0 };
		ist >> x;
		int y{ 0 };
		ist >> y;
		Point a{};
		a.x = x;
		a.y = y;

		p.push_back(a);

		if (ist.eof()) break;		
	}

}

string compare(const vector<Point>& p, const vector<Point>& o) 
{
	string s{ "Something's wrong" };
	if (p.size() != o.size()) return s;

	for (int i{}; i < p.size(); i++) {
		if (p[i].x != o[i].x) return s;
		if (p[i].y != o[i].y) return s;
	}
	return "Ok !";
}

int main()
try{
	/*cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname }; // ist is an input stream for the file named name
	if (!ist) error("can't open input file ", iname);
	*/


	vector<Point> original_points;
	int inp_numb{7};
	cout << "Enter the number of x, y pairs you want : ";
	cin >> inp_numb;
	cout << "Enter " << inp_numb << " pair of x, y : ";
	
	for (int i{ 0 }; i < inp_numb; i++)
	{
		int x{};
		int y{};

		cin >> x >> y;

		Point stock{ x, y };

		original_points.push_back(stock);		
	}
	
	write_file(original_points);

	vector<Point> processed_points;

	read_file(processed_points);

	print_vec_point(processed_points);

	cout << compare(original_points, processed_points);


}

catch (exception & e)
{
	cerr << e.what();
}

catch (...)
{
	cerr << "Unknown expression\n";
}