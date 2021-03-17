/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"

int main()
{
	using namespace Graph_lib;
	
	Simple_window win(Point{100,100},600,600,"Ablak");
	
	Axis x{Axis::x,Point{100, 300}, 400, 20,"x"};
	Axis y{Axis::y,Point{300, 500}, 400, 20,"y"};
	x.set_color(Color::red);
	y.set_color(Color::red);
	
	win.attach(x);
	win.attach(y);
	
	win.wait_for_button();
}
