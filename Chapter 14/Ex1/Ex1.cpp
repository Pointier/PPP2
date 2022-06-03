#include "../Debugged/Graph.h"
#include "../Debugged/Simple_window.h"

namespace Graph_lib
{
	class Arc : public Shape
	{
	public:
		Arc(Point p, int ww, int hh, int aa1, int aa2);

		void draw_lines() const;
		Point center() const;
		int weight() const { return w; }
		int height() const { return h; }


	private:
		int w;
		int h;
		int a1;
		int a2;
	};
	Arc::Arc(Point p, int ww, int hh, int aa1, int aa2)
		:w{ ww }, h{ hh }, a1{ aa1 }, a2{ aa2 }
	{
		add(Point{ p.x - w ,p.y - h });
	}

	Point Arc::center() const
	{
		return { point(0).x + w,point(0).y + h };
	}

	void Arc::draw_lines() const
	{
		if (color().visibility())
			fl_arc(point(0).x, point(0).y, w * 2, h * 2, a1, a2);
	}


	class Smiley : public Circle
	{
	public :
		Smiley(Point pp, int rr)
			: Circle(pp, rr), a(Point{ pp.x + (rr / 2),pp.y }, rr / 2, rr / 2, 40, 135), le(Point{ pp.x - (rr / 2),pp.y - (rr / 2) }, rr / 2), ri(Point{ pp.x + (rr / 2),pp.y - (rr / 2) }, rr / 2)
		{
			
		}

		void draw_lines() const;


	private :
		Arc a;
		Circle le;
		Circle ri;
	};

	void Smiley::draw_lines() const 
	{
		Circle::draw_lines();
		a.draw_lines();
		le.draw_lines();
		ri.draw_lines();

	}
}

int main()
{
	Simple_window win(Point{ 200,200 }, 800, 600, "Lul");

	Smiley a(Point{200,200 }, 100);
	a.set_color(Color::black);

	win.attach(a);
	win.wait_for_button();
}