#pragma once
#define _USE_MATH_DEFINES
#include "../Debugged/Graph.h"
#include <cmath>


using namespace Graph_lib;

class Regular_hexagon : public Closed_polyline
{
public:
	Regular_hexagon(Point pp, int rr)
		:p{ pp }, r{ rr }
	{
		 generate_points();
	};
	
	void generate_points();
	void draw_lines() const;


	

	vector<Point> pts;	
	Point p;
	int r;
};

class Regular_hexagons 
{
public:
	Regular_hexagons(Point pp, int rr)
		:p{ pp }, r{ rr }
	{
		coord();
	}
	
	void coord();
	void draw_lines() const;

	vector<Regular_hexagon> tile;
private :
	
	Point p;
	int r;


};
