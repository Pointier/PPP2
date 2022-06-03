#pragma once
#include "../Debugged/Graph.h"

namespace Graph_lib {

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

	class Box : public Shape
	{
	public:
		Box(Point pp, int ww, int hh);

		void draw_lines() const;


	private:
		Point p;
		int w;
		int h;

	};

	class Line_h : public Shape
	{
		Line_h(Point pp1, Point pp2);

		void side();
		void draw_lines() const;


	private :
		int ori;
		Point p1;
		Point p2;
	};

	
}