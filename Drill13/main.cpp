/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"



int main()
{
    using namespace Graph_lib;

    Point tl {100,100};
   
    Simple_window win {tl, 800, 1000, "Canvas"};
    

    int x_grid=100;
    int y_grid=100;
    
    Lines grid;
    for(int x=x_grid; x<=800; x+=100)
    	grid.add(Point{x,0}, Point{x,800});
    for(int y=y_grid; y<900; y+=100)
    	grid.add(Point{0,y}, Point{800,y});
    	
    Vector_ref <Rectangle> r;
    for(int i=0; i<8; ++i)
    { 
    	r.push_back (new Rectangle(Point{i*100,i*100},100,100));
    	r[i].set_fill_color(Color::red);
    	r[i].set_color(Color::red);
    	win.attach(r[i]);
    }	
    
    Image ny1(Point{0,200},"nyarla.jpg");
    ny1.set_mask(Point{0,0},200,200);
    Image ny2(Point{200,0},"nyarla.jpg");
    ny2.set_mask(Point{0,0},200,200);
    Image ny3(Point{200,400},"nyarla.jpg");
    ny3.set_mask(Point{0,0},200,200);
    Image ny4(Point{400,600},"nyarla.jpg");
    ny4.set_mask(Point{0,0},200,200);
    
    	win.attach(ny1);
    	win.attach(ny2);
    	win.attach(ny3);
    	win.attach(ny4);
    	win.attach(grid);
    	
    	
    win.wait_for_button();
    
    Image s(Point{0,0},"smiley.jpg");
    s.set_mask(Point{0,0},100,100);
    int newx=0;
    int newy=0;
    int x=0;
    int y=0;
    win.attach(s);
    

    
    for(int a=0; a<8; ++a)
    {
    	y=a;
    	for(int i=0; i<8; ++i)
    	{
    		x=i;
    		newx= 100 * x -s.point(0).x;
    		newy= 100 * y -s.point(0).y;
    		s.move(newx,newy);
    		win.set_label("Canvas");
    		win.wait_for_button();
    	}
    	
    }
}
