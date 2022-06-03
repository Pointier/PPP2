#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities

int main()
{
	using namespace Graph_lib; // our graphics facilities are in Graph_lib
	Point tl{ 660,340 }; // to become top left corner of window
	Simple_window win{ tl,1050,700,"My window" }; // make a simple window
	
	Axis xa{ Axis::x, Point{20,300},280,10,"x axis" };
	xa.set_color (Color::black);
	win.attach(xa);

	Axis ya{ Axis::y, Point{20,300},280,10,"y axis" };
	ya.set_color(Color::black);
	win.attach(ya);

	Function sine{ sin,0,10,Point{20,150},1000,25,75 };
	sine.set_color(Color::red);
	win.attach(sine);

	Graph_lib::Polygon poly; // a polygon; a Polygon is a kind of Shape
	poly.add(Point{ 300,400 }); // three points make a triangle
	poly.add(Point{ 400,100 });
	poly.add(Point{ 500,400 });
	poly.set_color(Color::dark_cyan);
	poly.set_style(Line_style::dash);
	win.attach(poly);

	Graph_lib::Rectangle r{ Point{200,200}, 100, 50 }; // top left corner, width, height
	r.set_color(Color::dark_red);
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point{ 50,75 });
	poly_rect.add(Point{ 100,50 });
	poly_rect.add(Point{ 200,50 });
	poly_rect.add(Point{ 100,100 });
	poly_rect.add(Point{ 200,100 });	
	poly_rect.add(Point{ 400,120 });	
	poly_rect.set_color(Color::magenta);
	win.attach(poly_rect);

	r.set_fill_color(Color::yellow); // color the inside of the rectangle
	poly.set_style(Line_style(Line_style::dash, 4));
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);

	Text t{ Point{150,150}, "Hello, graphical world!" };
	t.set_color(Color::dark_yellow);
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.attach(t);
	
	//Image ii{ Point{100,50},"img.jpg" }; // 400*212-pixel jpg
	//win.attach(ii);

	Circle c{ Point{100,200},50 };
	Graph_lib::Ellipse e{ Point{100,200}, 75,25 };
	e.set_color(Color::dark_red);
	c.set_color(Color::red);
	Mark m{ Point{100,200},'x' };
	ostringstream oss;
	
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);

	win.wait_for_button(); // give control to the display engine
}