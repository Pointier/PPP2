#include "../Debugged/Graph.h"
#include "../Debugged/Simple_window.h"

using namespace Graph_lib;

int main()
{


	constexpr int xmax = 600; // window size
	constexpr int ymax = 600;
	constexpr int x_orig = xmax / 2; // position of (0,0) is center of window
	constexpr int y_orig = ymax / 2;
	Point orig{ 300,300 };
	constexpr int r_min = -10; // range [–10:11)
	constexpr int r_max = 11;
	constexpr int n_points = 400; // number of points used in range
	constexpr int x_scale = 20; // scaling factors
	constexpr int y_scale = 20;

	Simple_window win(Point{ 200,200 }, xmax, ymax, "Functions graphs");



	Axis x(Axis::x, Point{ 100,y_orig }, n_points, n_points / 20, "1==20 pixels");
	x.set_color(Color::red);

	Axis y(Axis::y, Point{ x_orig,500 }, n_points, n_points / 20, "1==20 pixels");
	y.set_color(Color::red);
	
	win.attach(x);
	win.attach(y);

	Function one{ [](double x)->double {return 1; }
	, r_min, r_max, orig, 400,x_scale,y_scale};
	one.set_color(Color::black);
	win.attach(one);

	Function slope{ [](double x) {return x / 2; }
	,r_min,r_max,orig,n_points,x_scale,y_scale };
	slope.set_color(Color::green);
	win.attach(slope);

	Function cosine{ [](double x) {return cos(x); }
			,r_min,r_max,orig,n_points,x_scale,y_scale };
	cosine.set_color(Color::blue);
	win.attach(cosine);

	Function sloping_cos{ [](double x) {return x / 2+ cos(x); }
	,r_min,r_max,orig,n_points,x_scale,y_scale };
	sloping_cos.set_color(Color::yellow);
	win.attach(sloping_cos);

	win.wait_for_button();
}