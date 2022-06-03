//  Chapter 6 Exercise 6

#include "../../std_lib_facilities.h"


vector<string> conjonction{ "and","or","but" };
vector<string> noun{ "birds", "fish", "c++" };
vector<string> verb{ "rules", "fly","swim" };

class Input_string {
public :
	
	string get();
	void putback(string input);

private:
	bool full{false};
	string buffer{""};

};

void Input_string::putback(string input) {
	if (full) error("Buffer is already full");
	buffer = input;
	full = true;
}

string Input_string::get() {
	if (full) {
		full = false;
		return buffer;

	}
		string input{ "" };
		cin >> input;
		return input;
}

Input_string is;



bool isanoun() {
	string input{ "" };
	input = is.get();
	for (string n : noun) {
		if (input == n)
			return true;
	}
	return false;
}

bool isasverb() {
	string input{ "" };
	input = is.get();
	for (string n : verb) {
		if (input == n)
			return true;
	}
	return false;
}
bool isaconjunction() {
	string input{ "" };
	input = is.get();
	for (string n : conjonction) {
		if (input == n)
			return true;
	}
	return false;
}

bool isadot() {
	string input{ "" };
	input = is.get();
	
		if (input == ".")
			return true;

		is.putback(input);
	
	return false;
}
bool isasentence() {
	if (isanoun())
		if (isasverb())
			if (isadot())
				return true;
			else {
				
				if (isaconjunction())
					return isasentence();
			}
			else
				return false;

				
			


}

int main() 
try {
	while (true) {
		string input{""};
		bool ok{ false };
		input = is.get();
	
		if (input == "x")
			break;
		else
			is.putback(input);

		ok = isasentence();
		
		if (ok) {
			cout << "Sentence is ok !\n";
			cout << "Continue or enter x to quit\n";
		}
		else {
			cout << "Sentence is not ok !\n";
			cout << "Try again !\n";
		}

		/*else
			ok = isasentence;
		if (ok)
			cout << "Sentence is ok\n";
		else
			cout << "Sentence is not ok\n";*/

	}
	return 0;
}

catch (exception & e) {
	cerr << "Error : " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Oops : Unknown exception!\n";
	return 2;
}