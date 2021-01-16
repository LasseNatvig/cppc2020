 /// palette.cpp, PPP section 13.10, the 256 colors in the FLTK palette
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;
int main() {
	Simple_window win{Point{ 100, 100 }, 400, 350, "16 x 16 color matrix"};
	Vector_ref<Rectangle> vr;
	for (int i = 0; i < 16; ++i) { // From PPP page 467
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new Rectangle{ Point{ i * 20, j * 20 }, 20, 20 });
			vr[vr.size() - 1].set_fill_color(Color{ i * 16 + j });
			win.attach(vr[vr.size() - 1]);
			cout << '[' << i << ',' << j << "] colorvalue: " << i * 16 + j << endl;
		}
	}
	win.wait_for_button();
};