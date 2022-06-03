// Drill1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../std_lib_facilities.h"
/*
//§9.4.1
struct Date {
	int y; // year
	int m; // month in year
	int d; // day of month
};

void init_date(Date& d,int yy, int mm, int dd)
{
	if (mm < 1 || mm>12) throw std::runtime_error("Month is wrong");
	if (dd < 1 || dd>31) throw std::runtime_error("Day is wrong");

	d.y = yy;
	d.m = mm;
	d.d = dd;
}

Date add_day(Date d)
{
	d.d = (d.d == 31) ? 1 : d.d = d.d+1;
	return d;
}

int main()
try{
	Date today;
	init_date(today,1978,6,27);
	Date tomorrow =add_day( today);
	std::cout << "Today : " << today.d << '\n'
		<< "Tomorrow : " << tomorrow.d;

}

catch (std::exception & s)
{
	std::cerr << s.what();
}
*/
/*
//§9.4.2

struct Date {
	int y, m, d; // year, month, day
	Date(int yy, int mm, int dd);
		 // check for valid date and initialize
	void add_day(int n); // increase the Date by n days
};

Date::Date(int yy,int  mm,int  dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (mm < 1 || mm>12) throw std::runtime_error("Month is wrong");
	if (dd < 1 || dd>31) throw std::runtime_error("Day is wrong");
}

void Date::add_day(int n)
{
	for (int i{ 0 }; i < n; i++)
	d = (d == 31) ? 1 : d = d + 1;
}

int main()
try {
	Date today{ 1978, 6, 27 };
	Date tomorrow = { today };
	tomorrow.add_day(36);
	std::cout << "Today : " << today.d << '\n'
		<< "Tomorrow : " << tomorrow.d;

}

catch (std::exception & s)
{
	std::cerr << s.what();
}
*/
/*
//§9.4.3

class Date {
	int y, m, d; // year, month, day
public:
	Date(int y, int m, int d); // check for valid date and initialize
	void add_day(int n); // increase the Date by n days
	int month() { return m; }
	int day() { return d; }
	int year() { return y; }
};

Date::Date(int yy, int  mm, int  dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (mm < 1 || mm>12) throw std::runtime_error("Month is wrong");
	if (dd < 1 || dd>31) throw std::runtime_error("Day is wrong");
}

void Date::add_day(int n)
{
	for (int i{ 0 }; i < n; i++)
		d = (d == 31) ? 1 : d = d + 1;
}

int main()
try {
	Date today{ 1978, 6, 27 };
	Date tomorrow = { today };
	tomorrow.add_day(36);
	std::cout << "Today : " << today.d << '\n'
		<< "Tomorrow : " << tomorrow.d;

}

catch (std::exception & s)
{
	std::cerr << s.what();
}
*/
/*
//§9.7.1
enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
// simple Date (use Month type)
class Date {
public:
	Date(int y, Month m, int d); // check for valid date and initialize
	void add_day(int n); // increase the Date by n days
	Month month() { return m; }
	int day() { return d; }
	int year() { return y; }
	// . . .
private:
	int y; // year
	Month m;
	int d; // day
};

Date::Date(int yy, Month  mm, int  dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (dd < 1 || dd>31) throw std::runtime_error("Day is wrong");
}

void Date::add_day(int n)
{
	for (int i{ 0 }; i < n; i++)
		d = (d == 31) ? 1 : d = d + 1;
}

static ostream& operator<< (ostream& os, const Month& m) {
	switch (m) {
	case Month::jan: os << "January"; break;
	case Month::feb: os << "February"; break;
	case Month::mar: os << "March"; break;
	case Month::apr: os << "April"; break;
	case Month::may: os << "May"; break;
	case Month::jun: os << "June"; break;
	case Month::jul: os << "July"; break;
	case Month::aug: os << "August"; break;
	case Month::sep: os << "September"; break;
	case Month::oct: os << "October"; break;
	case Month::nov: os << "November"; break;
	case Month::dec: os << "December"; break;
	}
	return os;
}


ostream& operator<<(ostream& os, Date& d)
{
	
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}





int main()
try {
	Date today{ 1978, Month(6), 27 };
	Date tomorrow = { today };
	tomorrow.add_day(36);
	std::cout << "Today : " << today << '\n'
		<< "Tomorrow : " << tomorrow;

}

catch (std::exception & s)
{
	std::cerr << s.what();
}



*/

//§9.7.4

enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
	// . . .
	Date(int yy, Month  mm, int  dd);
	int day() const; // const member: can’t modify the object
	Month month() const; // const member: can’t modify the object
	int year() const; // const member: can’t modify the object
	void add_day(int n); // non-const member: can modify the object
	void add_month(int n); // non-const member: can modify the object
	void add_year(int n); // non-const member: can modify the object
private:
	int y; // year
	Month m;
	int d; // day of month
};

Date::Date(int yy, Month  mm, int  dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (dd < 1 || dd>31) throw std::runtime_error("Day is wrong");
}

int Date::day() const
{
	return d;
}

Month Date::month() const
{
	return m;
}

int Date::year() const
{
	return y;
}

void Date::add_day(int n)
{
	for (int i{ 0 }; i < n; i++)
		d = (d == 31) ? 1 : d += 1;
}

void Date::add_month(int n)
{
	int x{ 0 };
	for (int i{ 1 }; i < 13; i++)
	{
		if (Month(i) == Month(m)) x = i;
	}
	
	if (n < 1) m = Month::jan;
	else if (n > 12) m = Month::dec;
	else for (int i{ 0 }; i < n; i++)
	{
		m = (Month(m) == Month(12)) ? Month(1) : m = Month(x + 1);
		x += 1;
	}

}

void Date::add_year(int n)
{

}

static ostream& operator<< (ostream& os, const Month& m) {
	switch (m) {
	case Month::jan: os << "January"; break;
	case Month::feb: os << "February"; break;
	case Month::mar: os << "March"; break;
	case Month::apr: os << "April"; break;
	case Month::may: os << "May"; break;
	case Month::jun: os << "June"; break;
	case Month::jul: os << "July"; break;
	case Month::aug: os << "August"; break;
	case Month::sep: os << "September"; break;
	case Month::oct: os << "October"; break;
	case Month::nov: os << "November"; break;
	case Month::dec: os << "December"; break;
	}
	return os;
}


ostream& operator<<(ostream& os, Date& d)
{

	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}

int main()
try {
	Date today{ 1978, Month(6), 27 };
	Date tomorrow = { today };
	tomorrow.add_day(36);
	tomorrow.add_month(6);
	std::cout << "Today : " << today << '\n'
		<< "Tomorrow : " << tomorrow;

}

catch (std::exception & s)
{
	std::cerr << s.what();
}