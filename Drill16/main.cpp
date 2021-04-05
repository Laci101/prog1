#include "../GUI.h"
#include "../Lines_window.h"

int main()
{
    Lines_window win {Point{100, 100}, 600, 400, "lines"};
    return gui_main();
}

/*
    g++ main.cpp ../Graph.cpp ../Window.cpp ../GUI.cpp ../Lines_window.cpp -o main `fltk-config --ldflags --use-images`
*/