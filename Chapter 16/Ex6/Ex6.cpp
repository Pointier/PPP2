#include <ctime>
#include <chrono>
#include <thread>
#include "../Debugged/Graph.h"
#include "../Debugged/Window.h"
#include "../Debugged/GUI.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace Graph_lib
{
	class Hour : public Window
	{
	public:
		Hour(int w, int hh, const string& title);

	private:
		void quit();
		void time();
		Point p{ x_max() / 2,y_max() / 2 };
		const int ra{ 100 };
		Circle c;
		Vector_ref<Line> h;
		Vector_ref<Line> m;
		Vector_ref<Line> s;
		Button quit_button;
	};

	Hour::Hour(int w,int hh, const string& t)
		:Window{ w,hh,t }, c{ p, ra },
		
		quit_button{Point{x_max()-70,20},70,20,"quit",
		[](Address,Address pw) {reference_to<Hour>(pw).quit(); } }
	{
		for (int i{ 0 }; i < 12; i++)
		{
			double xx = ra * cos((M_PI / 6));
			double yy = ra * sin((M_PI / 6));
			h.push_back(new Line(p, Point{ p.x + narrow_cast<int>(xx) ,p.y + narrow_cast<int>(yy) }));
			h[i].set_color(Color::green);
			h[i].draw();
		}
		c.set_color(Color::black);
		
		for (int i{ 0 }; i < 61; i++)
		{
			double xx = ra * cos((M_PI / 30));
			double yy = ra * sin((M_PI / 30));
			m.push_back(new Line(p, Point{ p.x + narrow_cast<int>(xx) ,p.y + narrow_cast<int>(yy) }));
			m[i].set_color(Color::red);
			m[i].draw();
		}

		for (int i{ 0 }; i < 62; i++)
		{
			double xx = ra * cos((M_PI / 30));
			double yy = ra * sin((M_PI / 30));
			s.push_back(new Line(p, Point{ p.x + narrow_cast<int>(xx) ,p.y + narrow_cast<int>(yy) }));
			s[i].set_color(Color::blue);
			s[i].draw();
		}
		c.set_color(Color::black);
		c.draw_lines();		
		attach(c);
		
		
		attach(quit_button);

		time();
	}

	void Hour::quit()
	{
		hide(); // curious FLTK idiom to delete window
	}

	void Hour::time()
	{
		const std::time_t now = std::time(nullptr); // get the current time point
		#pragma warning(suppress : 4996)
		const std::tm calendar_time = *std::localtime(std::addressof(now));
		int hour{ 0 };
		int min{ 0 };
		int second{ 0 };

		while(true)
		{
			if (hour != calendar_time.tm_hour)
			{
				hour = calendar_time.tm_hour;

				attach(h[hour]);
			}

			if (min != calendar_time.tm_min)
			{
				min = calendar_time.tm_min;

				attach(m[min]);
			}

			if (second != calendar_time.tm_sec)
			{
				second = calendar_time.tm_sec;

				attach(s[second]);
			}

		}
	}
}

int main()
{
	Graph_lib::Hour h(1024, 768, "Leurre");
	return Graph_lib::gui_main();

	//std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
