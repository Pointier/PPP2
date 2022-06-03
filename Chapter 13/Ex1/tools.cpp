#include "tools.h"
#include "../Debugged/Simple_window.h"


namespace Graph_lib {

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


	Box::Box(Point pp, int ww, int hh)
		:p{pp},w {ww}, h{ hh }
	{
		add(p);
	}

	void Box::draw_lines() const
	{
		
		
		fl_line(point(0).x +20, point(0).y, point(0).x+w-20 , point(0).y );
		fl_line(point(0).x , point(0).y + 20, point(0).x  , point(0).y+h - 20);
		fl_line(point(0).x+w , point(0).y + 20, point(0).x+w, point(0).y+h - 20);
		fl_line(point(0).x + 20, point(0).y+h, point(0).x + w - 20, point(0).y+h);

		fl_arc(point(0).x, point(0).y, 40, 40, 90, 180);
		fl_arc(point(0).x+w-40, point(0).y , 40, 40, 0, 90);
		fl_arc(point(0).x , point(0).y+h-40, 40, 40, 180, 270);
		fl_arc(point(0).x+w + -40, point(0).y+h-40, 40, 40, 270,360);

		
				
	}

	Line_h::Line_h(Point pp1, Point pp2)
		:p1{ pp1 }, p2{ pp2 }
	{
	}
	void Line_h::side()
	{
		if ()
	}

}