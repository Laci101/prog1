/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "../Simple_window.h"
#include "../Graph.h"



int main()
{
    using namespace Graph_lib;

    Point tl {100,100};
    int hanypont=1000;
    int scale=50;
    int width=100;
    int height=50;
    
   
    Simple_window win {tl, 600,400, "Canvas"};
    
   
    
    Axis x{Axis::x,Point{20, 300}, 280, 10,"x"};
    Axis y{Axis::y,Point{20, 300}, 280, 10,"y"};
    
    Function sinus(sin,0,100,Point{20,150},hanypont,scale,scale);
    sinus.set_color(Color::red);
    
    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});
    poly.set_color(Color::yellow);
    poly.set_style(Line_style::dash);
    
    Rectangle r(Point{200,200},width,height);
    
    Closed_polyline poly_rect;
    poly_rect.add(Point{100,50});
    poly_rect.add(Point{200,50});
    poly_rect.add(Point{200,100});
    poly_rect.add(Point{100,100});
    poly_rect.add(Point{50,75});
    r.set_fill_color(Color::blue);
    r.set_style(Line_style(Line_style::dash,2));
    
    Text t(Point{150,150},"Tiszteletem!");
    t.set_color(Color::red);
    t.set_font(Font::times_bold);
    t.set_font_size(40);
    
    Image ii(Point{100,50},"macska.jpeg");
 
    
    win.attach(ii);
    win.attach(t);
    win.attach(poly_rect);
    win.attach(r);
    win.attach(poly);
    win.attach(sinus);
    win.attach(x);
    win.attach(y);
    

    win.wait_for_button();

}
