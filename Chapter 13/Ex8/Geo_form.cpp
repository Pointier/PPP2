#include "Geo_form.h"

using namespace Graph_lib;



void Regular_hexagon::generate_points()
{
	int n = 6;
	for (int i = 0; i < n; i++) {
		pts.push_back(Point(p.x + r * cos(2 * M_PI * i / n), p.y + r * sin(2 * M_PI * i / n)));
		add(pts[i]);
	}
};


void Regular_hexagon::draw_lines() const
{
	Closed_polyline::draw_lines();
}

void Regular_hexagons::coord()
{
	int tile_size{ 8 };
	double a;
	a = sqrt(3) / 2 * r;
	int d = round(a);

	for (int i{}; i < tile_size; i++)
	{
		Point n;
		if (i < 4)
		{
			
			n.x = p.x + (i * d * 2);
			n.y = p.y;
			
			
		}
		else
		{
			n.x = p.x + r;
			n.y = p.y+ (i * r * 2);
		}

		
		Regular_hexagon h(n, r);
	}
	
}

void Regular_hexagons::draw_lines() const
{
	for (int i{}; i < tile.size(); i++)
	{
		
	}
}
