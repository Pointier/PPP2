#include "../../std_lib_facilities.h"

class Token
{
public:
	char kind;        // what kind of token
	double value;     // for numbers (for others this will be zero)
	//Contructor1: make a Token from a char
	Token(char ch)
		:kind(ch), value(0) { }
	//Constructor 2: make a Token from a char and a double
	Token(char ch, double val)
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream
{
public:
	Token get();      // use cin to get token
};

Token Token_stream::get()
{
	char ch;
	cout << "\nIn Token_stream::get(): enter a token: ";
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch)
	{
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
		return Token(ch);  // let each character represent itself
	case '.':        case '0':        case '1':        case '2':        case '3':
	case '4':        case '5':        case '6':        case '7':        case '8':
	case '9':
	{
		cin.putback(ch);    // put digit back into the input stream: extract double
		double val;
		cin >> val;              // read a floating-point number
		return Token('#', val);   // book uses 8 to represent number
	}
	default:
		error("Token_stream::get(): Invalid token.");
	}  //switch
} //token_stream::get()

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Welcome to the token stream explorer. Please enter your token(s).\n"
		<< "I can read numbers and simple arithmetic expressions : +, -, /, *, (, ).\n"
		<< "Enter an 'x' to exit. Other characters will generate an error.\n";

	Token_stream stream_instance;        // provides get() and putback()

	while (cin) //just keep reading until cin is fubar
	{
		Token t = stream_instance.get();
		cout << "Token kind|value: " << t.kind << " | " << t.value << "\n";
		if (t.kind == 'x')
			break;
	}
	cout << "\nFinished using token stream.\n";
	return 0;
} //try

catch (exception & e) {
	cerr << "Unspecified exception caught. e.what() == " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}