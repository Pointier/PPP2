
//
// Stroustrup - Programming Principles & Practice
//
// Chapter 17 Exercise 5
//
// Write a function, char* findx(const char* s, const char* x), that finds the
// first occurrence of the C-style string x in s.
//

#include <iostream>
#include <stdexcept>

using std::cout;

const char* findx(const char* s, const char* x) {
	if (x == 0) return s;
	for (int i = 0; s[i]; ++i) {
		if (s[i] == x[0]) {                     // found first matching char
			for (int j = 1; x[j]; ++j) {        // loop through substring
				if (s[i + j] != x[j]) break;        // does not match
				if (x[j + 1] == 0) return &s[i];    // found substring
				if (s[i + j + 1] == 0) return 0;      // s ended before substring
			}
		}
	}
	return 0;
}

int main()
try {
	char cs1[] = "For the Horde?";
	char cs2[] = "The";
	char cs3[] = "Alliance";

	const char* found = findx(cs1, cs2);
	const char* not_found = findx(cs1, cs3);

	if (found)
		cout << "Glory to the Horde!!" << found << '\n';

	if (not_found)
		cout << "Glory to the Alliance!!" << not_found << '\n';
}
catch (std::exception & e) {
	std::cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	std::cerr << "unknown exception\n";
	return 2;
}