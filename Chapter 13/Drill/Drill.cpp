#include "../Debugged/Simple_window.h";
#include "../Debugged/Graph.h";

 

int main()
{
	constexpr int xmax = 600; // window size
	constexpr int ymax = 600;
	constexpr int x_orig = xmax / 2; // position of (0,0) is center of window
	constexpr int y_orig = ymax / 2;
	constexpr Point orig{ x_orig,y_orig };
	constexpr int r_min = –10; // range [–10:11)
	constexpr int r_max = 11;
	constexpr int n_points = 400; // number of points used in range
	constexpr int x_scale = 30; // scaling factors
	constexpr int y_scale = 30;

	Simple_window win(Point{ 200,200 }, xmax, ymax, "Functions graphs");



	Axis x(Axis::x, x_orig, n_points, n_points / 20, "1==20 pixels");

	win.wait_for_button;
}