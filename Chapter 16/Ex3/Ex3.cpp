#include "../Debugged/Graph.h"
#include "../Debugged/Window.h"
#include "../Debugged/GUI.h"
#include<random>

namespace Graph_lib
{
	struct Ran_win : Window
	{
		Ran_win(int w,int h,const string& l);
	private:
		Button move_button;
		Button quit_button;
		Image img{ Point{-200,-200}, "img.jpg" };


		inline int rand_int(int min, int max);
	

		void move_b();
		void quit();
	};
	
	Ran_win::Ran_win(int w, int h, const string& l)
		:Window{w,h,l},
		move_button{ Point{x_max() / 2,y_max() / 2},500,500,"Move button",
		[](Address, Address pw) {reference_to<Ran_win>(pw).move_b(); } },
		quit_button{Point{x_max()-70,0},70,20,"quit",
		[](Address, Address pw) {reference_to<Ran_win>(pw).quit(); } }
	{
		img.set_mask(Point{ 300,300 }, 500, 500);
		attach(move_button);
		attach(quit_button);
		attach(img);
	}

	void Ran_win::quit()
	{
		hide(); // curious FLTK idiom to delete window		
	}

	inline int Ran_win::rand_int(int min, int max)
	{
		static default_random_engine ran;
		return uniform_int_distribution<>{min, max}(ran);
	}

	void Ran_win::move_b()
	{
		constexpr int min_x{ 1 };
		constexpr int max_x{ 1024 };
		constexpr int min_y{ 1};
		constexpr int max_y{ 768 };

		int x{ rand_int(min_x,max_x) };
		int y{ rand_int(min_y,max_y) };
		Point i{ img.point(0) };
		Point b{ move_button.loc };
		x = x - b.x;
		y = y - i.y;
		img.move( x,y );
		move_button.move(x, y);

	}
}

int main()
{
	using namespace Graph_lib;
	Ran_win win(1024, 768, "Lal");

	return gui_main();

}