// graph1.cpp (a first step, code will be improved!)
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;
int main() {
	Point tl{ 100, 100 }; // tl is Top-Left corner of our window
	Point origo{ 40, 255 };
	Simple_window win{tl, 400, 300, "Lecture 2 Example graph_1"};
	Axis xa{Axis::x, origo, 330, 11, "Month"};
	win.attach(xa); // attach xa to the window, win
	xa.set_color(Color::black);
	Axis ya{Axis::y, origo, 210, 7, "Celsius"};
	win.attach(ya); // attach ya
	ya.set_color(Color::black);

	// two vectors of max and min temperatures in Trondheim for august 2017 to july 2018
	vector<int> maxTemp{ 17, 16, 9, 3, 1, 0, 0, 1, 9, 19, 15, 23 };
	vector<int> minTemp{ 10, 9, 5, -2, -3, -4, -6, -6, 1, 8, 8, 13 };

	Open_polyline oplMax;
	for (unsigned int i = 0; i < maxTemp.size(); i++) {
		oplMax.add(Point{ origo.x + static_cast<int>(i), origo.y - maxTemp[i] });
	}
	oplMax.set_color(Color::red);  
	win.attach(oplMax);

	Open_polyline oplMin;
	for (unsigned int i = 0; i < minTemp.size(); i++) {
		oplMin.add(Point{ origo.x + static_cast<int>(i), origo.y - minTemp[i] });
	}
	oplMin.set_color(Color::blue);
	win.attach(oplMin);

	win.wait_for_button();
};