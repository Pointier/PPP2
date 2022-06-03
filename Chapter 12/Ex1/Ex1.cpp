#include "../Debugged/Simple_window.h"
#include "../Debugged/Graph.h"

int main()
{
	using namespace Graph_lib;
	Simple_window w{ Point{200,200},1050,700,"The window" };
	//ex 1 and 2
	/*
	
	Graph_lib::Rectangle r{ Point{200,100},300,200 };
	w.attach(r);
	r.set_color(Color::black);

	Text t{ Point{350,200},"Howdy!" };
	t.set_color(Color::red);
	w.attach(t);

	Graph_lib::Polygon p;
	p.add(Point{ 300,300 });
	p.add(Point{ 400,300 });
	p.add(Point{ 400,400 });
	p.add(Point{ 300,400 });
	p.set_color(Color::blue);
	w.attach(p);
	*/

	//ex 3
	/*
	Graph_lib::Polygon h;
	h.add(Point{ 100,100 });
	h.add(Point{ 100,200 });
	h.add(Point{ 130,200 });
	h.add(Point{ 130,160 });
	h.add(Point{ 200,160 });
	h.add(Point{ 200,200 });
	h.add(Point{ 230,200 });
	h.add(Point{ 230,100 });
	h.add(Point{ 200,100 });
	h.add(Point{ 200,140 });
	h.add(Point{ 130,140 });
	h.add(Point{ 130,100 });
	h.set_color(Color::green);
	w.attach(h);

	Graph_lib::Polygon p;

	p.add(Point{ 250,100 });
	p.add(Point{ 250,200 });
	p.add(Point{ 280,200 });
	p.add(Point{ 280,160 });
	p.add(Point{ 330,155 });
	p.add(Point{ 320,140 });
	p.add(Point{ 300,140 });
	p.add(Point{ 280,120 });

	p.set_color(Color::blue);
	w.attach(p);
	*/

	//Ex 5
	/*
	Graph_lib::Rectangle huge{ Point{150, 150}, x_max() * 2 / 3, y_max() * 3 / 4 };
	huge.set_style(Line_style(Line_style::solid, 8));
	huge.set_color(Color::red);

	w.attach(huge);
	w.set_label("Ch 12 Ex 5");
	*/

	//Ex8
	/*
	Circle r(Point{ 800,200 }, 60);
	r.set_style(Line_style(Line_style::solid, 5));
	r.set_color(Color::red);

	Circle g(Point{ 740,260 }, 60);
	g.set_style(Line_style(Line_style::solid, 5));
	g.set_color(Color::green);

	Circle bk(Point{ 670,200 }, 60);
	bk.set_style(Line_style(Line_style::solid, 5));
	bk.set_color(Color::black);

	Circle y(Point{ 610,260 }, 60);
	y.set_style(Line_style(Line_style::solid, 5));
	y.set_color(Color::yellow);

	Circle b(Point{ 540,200 }, 60);
	b.set_style(Line_style(Line_style::solid, 5));
	b.set_color(Color::blue);

	w.attach(r);
	w.attach(g);
	w.attach(bk);
	w.attach(y);
	w.attach(b);
	*/

	//Ex12

	Graph_lib::Polygon t;
	t.set_color(Color::blue);




	w.wait_for_button(); // give control to the display engine
}