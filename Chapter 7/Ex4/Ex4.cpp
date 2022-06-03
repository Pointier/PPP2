
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.

Calculation:
	Statement
	Print
	Quit
	Calculation Statement

Statement :
	Declaration
	Expression

Declaration :
	"let" Name "=" Expression

Expression :
	Term
	Expression + Term
	Expression - Term

Term :
	Primary
	Term * Primary
	Term / Primary
	Term % Primary

Primary :
	(Expression)

	Number
	+Primary
	-Primary
	§Primary
	Primary ^ Primary
	Name

 Number:
	Floating-point-literal

*/

#include "../../std_lib_facilities.h"


struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { } // constructor kind
	Token(char ch, double val) :kind(ch), value(val) { } // constructor kind and value
	Token(char ch, string n) :kind(ch), name(n), value(0) { } // Error 1/3 compiler
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '#';
const char name = 'a';
const char square_root = 'S';
const char power = 'P';
const char con = 'C';

Token Token_stream::get() // Get character from cin
{
	if (full) { full = false; return buffer; }

	char ch;
	cin.get(ch);
	while (isspace(ch)) {
		if (ch == '\n') return Token(print); // if newline detected, return print Token
		cin.get(ch);
	}

	switch (ch) {
	case quit:
	case let:
	case square_root:
	case power:
	case ',':
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
		return Token(ch);
	case '.':	case '0':	case '1':	case '2':	case '3':	case '4':
	case '5':	case '6':	case '7':	case '8':	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // Error miss +
			cin.unget();
			if (s == "#") return Token(let); // A desactiver (différent du let défini) ?
			if (s == "exit") return Token(quit); // Error name instead of quit
			if (s == "const") return Token(con);
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c) // Clean the code to recover from mistake
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	bool constant;
	Variable(string n, double v, bool b) :name(n), value(v), constant(b) { }
};

class Symbol_table {
public:
	double get_value(string s);
	void set_value(string s, double d);
	bool is_declared(string s);
	double define_name(string s, double d, bool b);

private:
	vector  <Variable>var_table;
};

Symbol_table st;


double Symbol_table::get_value(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined name ", s);
}

/*double change_value(string s)
{
	double d{ 0 };
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == s) {
			names[i].value = expression();
			d = names[i].value;
			return d;
		}
	}
	error("change: undefined name ", s);
}*/

void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i <= var_table.size(); ++i)
		if (var_table[i].name == s) {
			if (var_table[i].constant) error(s, " is a constant");
			var_table[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return true;
	return false;
}

double Symbol_table::define_name(string s, double d, bool b)
// add (var,val) to var_table
{
	if (Symbol_table::is_declared(s)) error(s, " declared twice");
	var_table.push_back(Variable(s, d, b));
	return d;
}

Token_stream ts;

double expression();

double my_pow(double a, double b) {
	if (b == 0) return a;
	double res{ a };
	for (int i{ 1 }; i < b; i++)
		res *= a;

	return res;
}

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	case number:
		return t.value;

	case name:
	{
		Token t2 = ts.get();
		if (t2.kind == '=') {
			double d = expression();
			st.set_value(t.name, d);
			return d;
		}
		else {
			ts.unget(t2);
			return st.get_value(t.name);
		}
	}
	/*case name: {
		string namestock = t.name;
		t = ts.get();
		if (t.kind == '=') return change_value(namestock);
		else {
			ts.unget(t);
			return get_value(namestock);
		}
	}*/
	case square_root: {
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression();
		if (d < 0) error("negative number are not authorized with square root");
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return sqrt(d);
	}
	case power: {
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected");
		int i = expression();
		if (i != expression()) error("exponent can only be integer");
		if (i < 0) error("exponent need to be positive");
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return my_pow(d, i);
	}

	default:
		error("primary expected");
	}
}


double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		case '%':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left = fmod(left, d);
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration(bool b)
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string var_name = t.name;
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	st.define_name(var_name, d, b);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration(false);
	case con:
		return declaration(true);
	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get(); // eat ‘;’
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error & e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {
	// predefine names:
	st.define_name("pi", 3.14159, true);
	st.define_name("e", 2.718281828, true);
	st.define_name("k", 1000, true);

	calculate();
	return 0;
}
catch (exception & e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}

/*
Variables à tester :
2+3;
2*3;
2+3*5*4;
2*5+3*2;
6/2*3;
5%3;
let abc =50;
abc*2;
lol;
0.002+1;
80000000*2;
-25+6;
-2*4;


*/