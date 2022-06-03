#include "../Debugged/Graph.h"
#include "../Debugged/Simple_window.h"
#include "Geo_form.h"



int main()
try
{
	Simple_window win{ Point{200,200},800,600, "Hexa" };
	Regular_hexagons r( Point{300,200},200 );

	for (int i{}; i < r.tile.size(); i++)
	{
		r.tile[i].set_color(Color::black);
		win.attach(r.tile[i]);
	}
	win.wait_for_button();

}

catch (exception & e)
{
	cerr << e.what();
	return 1;
}

catch (...)
{
	cerr << "Unknown exception";
	return 2;
}