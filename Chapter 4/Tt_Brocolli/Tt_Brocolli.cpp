// Tt_Brocolli.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int main()
{
	std::vector<std::string> words;

	for (std::string temp; std::cin >> temp; )
	{
		words.push_back(temp);
	}
	std::vector<std::string> dislike{ "brocolli", "choux", "artichaud", "carotte", "tomate" };

	for (std::string word : words)
	{
		bool bad{ false };
		for (std::string hate : dislike) {
			if (hate == word)
				bad = true;
		}

		if (bad)
			std::cout << "Bleep\n";
		else
			std::cout << word <<'\n';
		
	}
	
   
}


