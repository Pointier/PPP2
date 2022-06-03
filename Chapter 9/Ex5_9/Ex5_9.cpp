// Ex5_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



// Chrono.cpp
#include "Chrono.h"

namespace Chrono {
	// member function definitions:
	Date::Date(int yy, Month mm, int dd)
		: y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}
	const Date& default_date()
	{
		static Date dd{ 2001,Month::jan,1 }; // start of 21st century
		return dd;
	}
	Date::Date()
		:y{ default_date().year() },
		m{ default_date().month() },
		d{ default_date().day() }
	{
	}
	void Date::add_day(int n)
	{
		// . . .
	}
	void Date::add_month(int n)
	{
		// . . .
	}
	void Date::add_year(int n)
	{
		if (m == Month::feb && d == 29 /*&& !leapyear(y + n)*/) { // beware of leap years!
			m = Month::mar; // use March 1 instead of February 29
			d = 1;
		}
		y += n;
	}
	// helper functions:
	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid
		if (d <= 0) return false; // d must be positive
		if (m < Month::jan || Month::dec < m) return false;
		int days_in_month = 31; // most months have 31 days
		switch (m) {
		case Month::feb: // the length of February varies
			days_in_month = /*(leapyear(y)) ? 29*/  28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}
		if (days_in_month < d) return false;
		return true;
	}
	/*bool leapyear(int y)
	{
		// see exercise 10
	}*/

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

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day() << ')';
	}
	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
			is.clear(ios_base::failbit); // set the fail bit
			return is;
		}
		dd = Date(y, Month(m), d); // update dd
		return is;
	}
	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};
	/*Day day_of_week(const Date& d)
	{
		// . . .
	}
	Date next_Sunday(const Date& d)
	{
		// ...
	}
	Date next_weekday(const Date& d)
	{
		// . . .
	}*/
} // Chrono



class Patron {
public :
	void user_fee();
	Patron(string n, int c, double f);

	//non modifying fct
	string get_name() const { return name; }
	int get_card_number() const { return card_number; }
	double get_fee() const { return fee; }
	
private :
	string name;
	int card_number;
	double fee;
	bool is_fee;
};

Patron::Patron(string n, int c, double f)
	:name{ n }, card_number{ c }, fee{ f }
{
	user_fee();
}

void Patron::user_fee() {
	if (fee != 0) is_fee = true;
	else is_fee = false;

}

struct ISBN {
	ISBN(int nn1, int nn2, int nn3, char xx)
		:n1{nn1},n2{nn2},n3{nn3},x{xx}
	{}
	int n1{};
	int n2{};
	int n3{};
	char x{};
};

enum class Genre {
	fiction = 1, nonfiction, periodical, biography, children
};

class Book {
public:
	Book(string t, string a, int c, ISBN I, Genre g);
	void book_validity();
	bool is_avail() { return available; }
	void check_in() { available = true; }
	void check_out() { available = false; }
	   	 
	//non modifying function
	string get_title() const { return title; }
	string get_author() const { return author; }
	ISBN get_ISBN() const { return IS; } 
private:
	ISBN IS;
	string title;
	string author;
	int copy_date{};
	bool available;
	Genre gen;
};

Book::Book(string t, string a, int c, ISBN I, Genre g)
	:title{t},author{a},copy_date{c},IS{I},gen{g}
{
	Book::book_validity();
}

void Book::book_validity()
{
	static const int min{ 1900 };
	static const int max{ 2100 };
	if (copy_date<min || copy_date>max)  error("Copyright date is invalid");

	if (!isalpha(IS.x) && !isdigit(IS.x))  error("ISBN is invalid");

}

bool  operator==(const Book& a, const Book& b)
{
	ISBN a1{ a.get_ISBN() };
	ISBN b1{ b.get_ISBN() };

	return (a1.n1 == b1.n1 && a1.n2 == b1.n2 && a1.n3 == b1.n3 && a1.x == b1.x);
}
bool operator!=(const Book& a, const Book& b)
{
	return!(a == b);
}

ostream& operator<<(ostream& os,const Book& a)
{
	
	return os << a.get_title() << '\n' << a.get_author()
		<< '\n' << a.get_ISBN().n1 << a.get_ISBN().n2
		<< a.get_ISBN().n3 << a.get_ISBN().x << '\n';

}


class Library {
public:
	void add_books();
	void add_patron();
	void both_here();
	void transa();
	void print_fees();


private:
	
	vector<Patron> pat;
	vector<Book> bo;
	vector<Transaction> tr;
};

void Library::add_books() {

	while (cin)
	{
		if (cin>>"stop")
	}
}

struct Transaction {
	Book b;
	Patron p;
	Chrono::Date d;
	};

int main()
try{
	
	ISBN s1(1, 2, 3, 'a');
	Book fun("Le lul", "Beta", 2050, s1, Genre::fiction);
	ISBN s2(1, 2, 3, 'a');
	Book kun("Le lul", "Beta", 2050, s2, Genre::fiction);
	if (fun == kun) cout << "Same ISBN !";
	if (fun != kun) cout << "Not the same ISBN !";
	cout << fun;
}

catch (exception & e)
{
	cerr <<e.what();
}

catch (...)
{
	cerr << "Unkwown error";
}


