// Ex3_Cities.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
int main()
{
	double distance{ 0.0 };
	std::cout << "Enter distance between cities along a road, to stop enter '|' \n";

	std::vector <double> cities;
	double total_distances{ 0 };
	double mean{ 0 };
	double smallest_dist{ 0 };
	double greatest_dist{ 0 };


	while (std::cin >> distance) {

		cities.push_back(distance);

		if (distance == '|')
			return 0;
		else {
			total_distances += distance;
			mean = total_distances / cities.size();
			if (smallest_dist == 0 && greatest_dist == 0) {
				smallest_dist = distance;
				greatest_dist = distance;
			}
			else if (smallest_dist > distance)
				smallest_dist = distance;
			else if (greatest_dist < distance)
				greatest_dist = distance;

		}
	}
		std::cout << "Total distances is " << total_distances << '\n';
		std::cout << "The mean distance between cities is " << mean << '\n';
		std::cout << "The smallest distance between cities is " << smallest_dist<<'\n';
		std::cout << "THe greatest distance between cities is " << greatest_dist << '\n';

    
}

