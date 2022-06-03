#include "../Debugged/Graph.h"
#include "../Debugged/Simple_window.h"

using namespace Graph_lib;

int main()
try{
	const Point orig{ 400,300 };
	constexpr int r1{ -10 };
	constexpr int r2{ 10 };
	constexpr int count{ 400 };
	constexpr int xscale{ 20 };
	constexpr int yscale{ 20 };


	Simple_window win(Point{ 200,200 }, 800, 600, "trig");

	Function sine{ [](double x) {return sin(x); },r1,r2,orig,count,xscale,yscale };
	sine.set_color(Color::cyan);

	Function cose{ [](double x) {return cos(x); },r1,r2,orig,count,xscale,yscale };
	cose.set_color(Color::red);

	Function cosasin{ [](double x) {return cos(x)+sin(x); },r1,r2,orig,count,xscale,yscale };
	cosasin.set_color(Color::blue);

	Function sqcossin{ [](double x) {return cos(x)*cos(x) + sin(x)*sin(x); },r1,r2,orig,count,xscale,yscale };
	sqcossin.set_color(Color::dark_green);

	Axis x(Axis::x, Point{200,300}, count, 20, "x axis");
	x.set_color(Color::black);
	Axis y(Axis::y, Point{ 400,500 }, count, 20, "y axis");
	y.set_color(Color::black);

	Text ts{ Point{200,275},"Cos and sin square" };
	ts.set_font_size(20);
	ts.set_color(Color::dark_green);
	win.attach(ts);

	win.attach(sine);
	win.attach(cose);
	win.attach(cosasin);
	win.attach(sqcossin);
	win.attach(x);
	win.attach(y);

	win.wait_for_button();

	return 0;
}

catch (exception & e)
{
	cerr << e.what();
}