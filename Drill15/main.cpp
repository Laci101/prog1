/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp  -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"


double one(double x) {return 1;}

double slope(double x)  {return x/2;}

double square(double x) { return x*x;}

double sloping_cos(double x) {return cos(x)+slope(x);}



int main()
{
	using namespace Graph_lib;
	
	Simple_window win(Point{100,100},600,600,"Ablak");
	
	Axis x{Axis::x,Point{100, 300}, 400, 20,"x"};
	Axis y{Axis::y,Point{300, 500}, 400, 20,"y"};
	x.set_color(Color::red);
	y.set_color(Color::red);
	
	const int yscale=20;
	const int xscale=20;
	
	Function a(one,-10,11,Point{300,300},400,xscale,yscale);
	Function sl(slope,-10,11,Point{300,300},400,xscale,yscale);
	Text sl_label(Point{sl.point(0).x,sl.point(20).y},"x/2");
	Function sq(square,-10,11,Point{300,300},400,xscale,yscale);
	Function cosine(cos,-10,11,Point{300,300},400,xscale,yscale);
	cosine.set_color(Color::blue);
	Function sloping_cosine(sloping_cos,-10,11,Point{300,300},400,xscale,yscale);
	sloping_cosine.set_color(Color::yellow);

	
	
	win.attach(x);
	win.attach(y);
	win.attach(a);
	win.attach(sl);
	win.attach(sl_label);
	win.attach(sq);
	win.attach(cosine);
	win.attach(sloping_cosine);
	
	win.wait_for_button();
}
