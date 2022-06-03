#include "../Debugged/Graph.h"
#include "../Debugged/Simple_window.h"
#include "tools.h"



	

	


int main()
{
	using namespace Graph_lib;
	Simple_window win{ Point{200,200},800,600,"Class" };
	
	Graph_lib::Arc a(Point{ 500,500 }, 110, 110, 0, 90);

	Circle b(Point{ 500,500 }, 100);
	b.set_color(Color::red);
	a.set_color(Color::blue);

	
	
	Box x(Point{ 100,100 }, 200, 100);
	x.set_color(Color::black);

	win.attach(x);

	win.attach(a);
	win.attach(b);

	win.wait_for_button();
}