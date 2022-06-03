#include "../Debugged/Graph.h"
#include "../Debugged/Simple_window.h"

namespace Graph_lib
{
	class Striped_rectangle : public Rectangle
	{
	public :
		Striped_rectangle(Point pp, int ww, int hh)
			:w{ ww }, h{ hh }, Rectangle(pp, ww, hh)
		{
			top_left_corner.x = pp.x ;
			top_left_corner.y = pp.y ;
			get_lines();
		}
		void get_lines();

		void draw_lines() const;
		
	private :
		Point top_left_corner;
		int w;
		int h;
		Lines l;
	};

	void Striped_rectangle::get_lines()
	{
		l.set_color(Color::black);
		Point p1 = top_left_corner;
		Point p2{ top_left_corner.x+w,top_left_corner.y };
		for (int i{ 3 }; i < h; i +=3)
		{
			p1.y = top_left_corner.y + i;
			p2.y = p1.y;
			l.add(p1, p2);
		}
	}

	void Striped_rectangle::draw_lines() const
	{
		Rectangle::draw_lines();
		l.draw_lines();
	}
}

int main()
{
	Simple_window win(Point{ 200,200 }, 800, 600, "Lul");

	Striped_rectangle r(Point{ 400,300 }, 100, 160);
	r.set_color(Color::red);

	win.attach(r);

	win.wait_for_button();

}