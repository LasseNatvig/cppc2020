 // Example program, discs
 // - demonstrates overloading of operator< for struct/class
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;
struct Disc{
	int radius;
	int x;
	int y;
	Disc(int r, int x, int y) : radius{r}, x{x}, y{y} {}; 
	bool operator<(const Disc& rhs) const { return (radius < rhs.radius); } // sort discs according to size
    // bool operator<(const Disc& rhs) const { return (x < (rhs.x)); } // sort discs according to x-coord
    // bool operator<(const Disc& rhs) const { return (x*y < (rhs.x*rhs.y)); } // sort discs according to x*y
};
vector<Disc> generateDiscs(int n) {
	vector<Disc> temp;
	for (int i = 0; i < n; i++) {
		int r = 1 + rand() % 100;
		int x = 10 + (rand() % (x_max() - 10));
		int y = 10 + (rand() % (y_max() - 10));
		temp.push_back(Disc{r,x,y});
	}
	return temp;
}
void showDiscs(vector<Disc> discVec, Vector_ref<Circle>& vrc, Simple_window& win){
	for (unsigned int i = 0; i < discVec.size(); i++) {
		int x = discVec.at(i).x;
		int y = discVec.at(i).y;
		int r = discVec.at(i).radius;
		vrc.push_back(new Circle{ Point{x, y}, r});
		// vrc[vrc.size() - 1].set_fill_color(Color::dark_green);
		vrc[vrc.size() - 1].set_fill_color(Color{rand() % 256});
		win.attach(vrc[vrc.size() - 1]);
	}
}
int main() {

	Simple_window win{ Point{10, 10}, 1800, 1200, "discs" };
	Vector_ref<Circle> display;
	vector<Disc> discs = generateDiscs(100000);
	// sort(discs.begin(), discs.end());
    sort(discs); // assumes std_lib_facilities 
	win.wait_for_button();
	showDiscs(discs, display, win);	
	win.wait_for_button();
}