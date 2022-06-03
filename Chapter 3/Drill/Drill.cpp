#include <iostream>

int main()
{
	std::cout << "Enter the name of the person you want to write to\n";
	std::string first_name;
	std::cin >> first_name;
	std::cout
		<< "Dear " << first_name << ",\n"
		<< "How are you ? \n";

	std::cout << "Enter the name of a person you both know\n";
	std::string friend_name;
	std::cin >> friend_name;
	std::cout << "Have you seen" << friend_name << "recently ?\n";

	std::cout << "Enter the sex of the person you both know (m or f)\n";
	char friend_sex;
	std::cin >>friend_sex;
	if (friend_sex == 'm')
		std::cout << "If you see " << friend_name << "please ask him to call me \n";
	
	if (friend_sex == 'f')
		std::cout << "If you see " << friend_name << "please ask her to call me \n";
	

	std::cout << "Enter the age of the recipient\n";
	int age;
	std::cin >> age;
	if(age <= 0)
		std::cout << "You're kidding !\n";
	if(age>=110)
		std::cout << "You're kidding !\n";

	if (age < 12)
		std::cout << "Next year you will be" << age + 1 << '\n';
	if (age == 17)
		std::cout << "Next year you will be able to vote\n";
	if (age > 70)
		std::cout << "I hope you are enjoying retirement\n";

	std::cout << "Yours sincerely,\n\n"
		<<"Hugo";




	return 0;
}

