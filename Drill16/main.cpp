#include "../Lines_window.h"
#include "../Graph.h"


int main()
{
	using namespace Graph_lib;
	Lines_window win{Point{100,100},1920,1000,"Canvas"};
	return gui_main();
}
