// Drill_Part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>  

bool read_unit(std::string unit) {
	bool unit_ok{ false };

	std::vector<std::string> good_unit{"m", "cm", "in", "ft"};

	for (std::string u : good_unit) 
		if (u == unit)
			unit_ok = true;
	
	return unit_ok;

}

double conversion(double temp, std::string unit) {
	constexpr int cm_to_m{ 100 };
	constexpr double in_to_m{ 0.0254 };
	constexpr double ft_to_m{ 0.3048 };
	double value{ 0.0 };

	if (unit == "m") 
		value = temp;
	   
	else if (unit=="cm")
		value = temp / cm_to_m; 
	
	else if (unit=="in")
		value = temp * in_to_m;
	
	else if (unit == "ft") 
		value = temp * ft_to_m;
	
	return value;
}

int main()
{
	double temp{ 0 };
	std::string unit{ "" };
	double lowest{ 0.0 };
	double largest{ 0.0 };
	double meters{ 0.0 };
	double sum{ 0.0 };
	int number_of_value{ 0 };
	

	std::vector <double> track;

	while (std::cin >> temp >> unit)
		if (temp == '|') {
			return 0;
		}
		else if (read_unit(unit) == false) {
				 std::cout << " Unit is illegal, please enter a good one.\n";
		}

		else {
			meters= conversion(temp, unit);
			number_of_value += 1;
			sum += meters;
			
			track.push_back(meters);
			

			if (lowest == 0.0 && largest == 0.0) {
				lowest = meters;
				largest = meters;
			}
			else if (meters < lowest) {
					lowest = meters;
					
			}
			else if (meters > largest) {
				
					largest = meters;
					
			}
			
		}
	std::sort(track.begin(), track.end());
	std::cout << "You have entered " << number_of_value << " value\n";
	std::cout << lowest << "m is the smallest so far\n";
	std::cout << largest << "m is the largest so far\n";
	for (int i : track) {
		int a{ 0 };
		a += 1;
		std::cout << "Value " << a << "is " <<i <<'m'<< '\n';
	}
	
	
}

