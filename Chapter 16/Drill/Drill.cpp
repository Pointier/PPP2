#include "../Debugged/Graph.h"
#include "../Debugged/Window.h"
#include "../Debugged/GUI.h"

namespace Graph_lib
{
	struct Lines_window : Window {
		Lines_window(Point xy, int w, int h, const string& title);
	private:
		// data:
		Open_polyline lines;
		// widgets:
		Button next_button; // add (next_x,next_y) to lines
		Button quit_button; // end program
		In_box next_x;
		In_box next_y;
		Out_box xy_out;
		Menu color_menu;
		Button color_menu_button;
		Menu line_style_menu;
		Button line_menu_button;
		void change(Color c) { lines.set_color(c); }
		void change_line_style(Line_style s) { lines.set_style(s); }
		void hide_menu() { color_menu.hide(); color_menu_button.show(); }
		void hide_line_menu() { line_style_menu.hide(); line_menu_button.show(); }
		// actions invoked by callbacks:
		void red_pressed() { change(Color::red); hide_menu(); }
		void blue_pressed() { change(Color::blue); hide_menu(); }
		void black_pressed() { change(Color::black); hide_menu(); }
		void color_menu_pressed() { color_menu_button.hide(); color_menu.show(); }
		void solid_pressed(){ change_line_style(Line_style::solid); hide_line_menu(); }
		void dash_pressed(){ change_line_style(Line_style::dash); hide_line_menu(); }
		void dot_pressed(){ change_line_style(Line_style::dot); hide_line_menu(); }
		void line_menu_pressed() { line_menu_button.hide(); line_style_menu.show(); }
		void next();
		void quit();
		// callback functions:
		static void cb_red(Address, Address);
		static void cb_blue(Address, Address);
		static void cb_black(Address, Address);
		static void cb_color_menu(Address, Address);
		static void cb_next(Address, Address);
		static void cb_quit(Address, Address);
		static void cb_solid(Address, Address);
		static void cb_dash(Address, Address);
		static void cb_dot(Address, Address);
		static void cb_line_menu(Address, Address);
		
	};

	Lines_window::Lines_window(Point xy, int w, int h, const string& title)
		:Window{ xy,w,h,title },
		next_button{ Point{x_max()-150,0}, 70, 20, "Next point", cb_next },
		quit_button{ Point{x_max()-70,0}, 70, 20, "Quit", cb_quit },
		next_x{ Point{x_max()-310,0}, 50, 20, "next x:" },
		next_y{ Point{x_max()-210,0}, 50, 20, "next y:" },
		xy_out{ Point{100,0}, 100, 20, "current (x,y):" },
		color_menu{ Point{x_max()-70,30},70,20,Menu::vertical,"color" },
		color_menu_button{ Point{x_max()-80,30}, 80, 20, "color menu", cb_color_menu },
		line_style_menu{ Point{x_max() - 70,85},70,20,Menu::vertical,"style" },
		line_menu_button{Point{x_max()-80,85},80,20,"style menu",cb_line_menu}

	{
		attach(next_button);
		attach(quit_button);
		attach(next_x);
		attach(next_y);
		attach(xy_out);
		xy_out.put("no point");
		color_menu.attach(new Button{ Point{0,0},0,0,"red",cb_red });
		color_menu.attach(new Button{ Point{0,0},0,0,"blue",cb_blue });
		color_menu.attach(new Button{ Point{0,0},0,0,"black",cb_black });
		attach(color_menu);
		color_menu.hide();
		attach(color_menu_button);
		line_style_menu.attach(new Button{ Point{0,0},0,0,"solid",cb_solid });
		line_style_menu.attach(new Button{ Point{0,0},0,0,"dash",cb_dash });
		line_style_menu.attach(new Button{ Point{0,0},0,0,"dot",cb_dot });
		attach(line_style_menu);
		line_style_menu.hide();
		attach(line_menu_button);
		attach(lines);
		}

	void Lines_window::quit()
	{
		hide(); // curious FLTK idiom to delete window
		
	}

	void Lines_window::next()
	{
		int x = next_x.get_int();
		int y = next_y.get_int();
		lines.add(Point{ x,y });
		// update current position readout:
		ostringstream ss;
		ss << '(' << x << ',' << y << ')';
		xy_out.put(ss.str());
		redraw();
	}
	
	void Lines_window::cb_red(Address, Address pw)
	{
		reference_to<Lines_window>(pw).red_pressed();
	}

	void Lines_window::cb_blue(Address, Address pw)
	{
		reference_to<Lines_window>(pw).blue_pressed();
	}

	void Lines_window::cb_black(Address, Address pw)
	{
		reference_to<Lines_window>(pw).black_pressed();
	}
	void Lines_window::cb_color_menu(Address, Address pw)
	{
		reference_to<Lines_window>(pw).color_menu_pressed();
	}
	void Lines_window::cb_next(Address, Address pw)
	{
		reference_to<Lines_window>(pw).next();
	}
	void Lines_window::cb_quit(Address, Address pw)
	{
		reference_to<Lines_window>(pw).quit();
	}
	void Lines_window::cb_solid(Address, Address pw)
	{
		reference_to<Lines_window>(pw).solid_pressed();
	}
	void Lines_window::cb_dash(Address, Address pw)
	{
		reference_to<Lines_window>(pw).dash_pressed();
	}
	void Lines_window::cb_dot(Address, Address pw)
	{
		reference_to<Lines_window>(pw).dot_pressed();
	}
	void Lines_window::cb_line_menu(Address, Address pw)
	{
		reference_to<Lines_window>(pw).line_menu_pressed();
	}
}

int main()
try {
	using namespace Graph_lib;
	Lines_window win{ Point{100,100},600,400,"lines" };
	
	return gui_main();
}
catch (exception & e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}