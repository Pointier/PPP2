// Ex12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()
try {
	vector<int> guess{};
	vector<int> u_input{};
	bool good{ false };
	int seed{};
	
	cout << "Enter a seed : \n";
	cin >> seed;
	srand(seed);
	if (!cin)
		error("Couldn't read integer from input\n");

	while (guess.size() < 4) {
		int a{ -1 };
		a = randint(9);
		bool same{ false };

		if (guess.size()==0)
			guess.push_back(a);
		else {
			for (int g : guess)
				if (g == a) {
					same = true;
				}
			if (!same)
				guess.push_back(a);
		}

	}
	
	for (int i{ 0 }; i < 4; ++i)
		cout << guess[i];

	while (!good) {
		cout << "Enter 4 different digits between 0 and 9, if digit is in correct position it is a bull,"
			<< " if you guess a digit but in  wrong place it is a cow.\n";
		for (int i{ 0 }; i < 4; ++i) {
			int x{ -1 };

			cin >> x;
			
			if (x <0|| x > 9 )
				error("You didn't enter a digit between 0 and 9 !");

			if (i >= 1) {
				for (int j{ 1 }; j <= u_input.size(); ++j) {
					if (u_input[j - 1] == x)
						error("You enter the same digit !");
				}
			}
			u_input.push_back(x);

			
		}

		int count_cow{ 0 };
		int count_bull{ 0 };

		for (int i{ 0 }; i < 4; ++i) {
			for (int j{ 0 }; j < 4; ++j) {
				if (u_input[i] == guess[j] && i == j)
					count_bull += 1;

				if (u_input[i] == guess[j] && i != j)
					count_cow += 1;
			}
		}
		u_input.clear();
		cout << "You have " << count_bull << " bull and " << count_cow << " cow !\n";
		if (count_bull == 4) {
			good = true;
			cout << "You won !";
		}

	}
}

catch (exception & e) {
	cerr << "error : " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Oops : unknown exception!\n";
	return 2;
}