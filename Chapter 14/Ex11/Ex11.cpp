#include "../Debugged/Graph.h"
#include "../Debugged/Simple_window.h"

namespace Graph_lib
{
	class Binary_tree : public Shape
	{
	public :
		Binary_tree(int i)
			:level{ i }
		{
			set_color(Color::blue);
			add_circles();
		}
		void add_circles();
		//void lines();
		void draw_lines() const;

	private :
		int level;
		Vector_ref<Circle> c;
		Lines l;
	};

	void Binary_tree::add_circles()
	{
		Point start_pos{ 350,100 };
		int r{ 25 };
		
		c.push_back(new Circle(start_pos,r));

		for (int i{ 1 }; i <= level; i++)
		{
			c.push_back(new Circle(Point{ start_pos.x - 50 * i,start_pos.y + 50 * i }, r));
			c.push_back(new Circle(Point{ start_pos.x + 50 * i,start_pos.y + 50 * i }, r));
		}

	}

	void Binary_tree::draw_lines() const
	{
		for (int i{ 0 }; i < c.size(); i++)
		{
			
			c[i].draw_lines();
		}
	}
}

int main()
{
	Simple_window win(Point{ 100,100 }, 800, 600, "Lol");
	
	Binary_tree b(2);
	b.set_color(Color::blue);
	win.attach(b);

	win.wait_for_button();

}