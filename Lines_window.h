#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title);
private:
    // data:
    Open_polyline lines;

    // widgets:
    Button next_button;     // add (next_x, next_y) to lines
    Button quit_button;     // end program
    In_box next_x;
    In_box next_y;
    Out_box xy_out;
    Menu color_menu;
    Button color_button;
    Menu style_menu;
    Button style_button;

    void change_c(Color c) { lines.set_color(c); }
    void change_s(Line_style s) { lines.set_style(s); }

    void hide_color() { color_menu.hide(); color_button.show(); }
    void hide_style() { style_menu.hide(); style_button.show(); }

    // actions invoked by callbacks:
    void red_pressed() { change_c(Color::red); hide_color(); }
    void blue_pressed() { change_c(Color::blue); hide_color(); }
    void black_pressed() { change_c(Color::black); hide_color(); }
    void yellow_pressed(){ change_c(Color::yellow); hide_color();}

    void dot_pressed() { change_s(Line_style::dot); hide_style(); }
    void dash_pressed() { change_s(Line_style::dash); hide_style(); }
    void solid_pressed() { change_s(Line_style::solid); hide_style(); }

    void color_pressed() { color_button.hide(); color_menu.show(); }
    void style_pressed() { style_button.hide(); style_menu.show(); }
    void next();
    void quit();

    // callback functions:
    /*
    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);
    static void cb_menu(Address, Address);
    static void cb_next(Address, Address);
    static void cb_quit(Address, Address);
    */
};

