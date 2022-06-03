

#include "../../std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
	
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
	Token buffer = 0;
private:
	bool full{ false };
};
	
  // here is where we keep a Token put back using putback()


// The putback() member function puts its argument back into the Token_stream's buffer
void Token_stream::putback(Token t)
{
	if (full)
		error("Attempted to putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full)
	{   //Is there a token already in the stream?
		full = false;
		return buffer; //note: buffer is just the previous Token instance
	}

	char ch;
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
		return Token(ch);        // let each character represent itself
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.putback(ch);    // put digit back into the input stream to recast as double
		double val;
		cin >> val;              // read a floating-point number
		return Token('#', val);   // let '8' represent "a number"
	}
	default:
		error("TOKEN STREAM ERROR: Bad token");
		return Token('z'); //dummy return just to avoid reaching end w/o return
	}  //switch
} //token_stream::get()


Token_stream ts;
int main()
try
{
	
	{	
		Token_stream ts;
		cin >> ts.buffer.kind;

			



		cout << ts.buffer.kind << '\n';
		}
	} //main


catch (exception & e) {
	cerr << "MAIN: Exception caught. e.what == " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}