  // graph_2.cpp (code will be improved!)
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;

int max(vector<int> v) {
	// assumes at least 1 element in v
	int max = v[0];
	for (unsigned int i = 1; i < v.size(); i++) {
		if (v[i] > max) max = v[i];
	}
	return max;
}
int min(vector<int> v) {
	// assumes at least 1 element in v
	int min = v[0];
	for (unsigned int i = 1; i < v.size(); i++) {
		if (v[i] < min) min = v[i];
	}
	return min;
}

int main() {
	Point tl{ 100, 100 }; // tl is Top-Left corner of our window
	Point origo{ 40, 255 };
	Simple_window win(tl, 400, 300, "Lecture 2 Example graph_2");
	Axis xa(Axis::x, origo, 330, 11, "Month");
	win.attach(xa); // attach xa to the window, win
	xa.set_color(Color::black);
	Axis ya(Axis::y, origo, 210, 7, "Celsius");
	win.attach(ya); // attach ya
	ya.set_color(Color::black);

	// two vectors of max and min temperatures in Trondheim for august 2017 to july 2018
	vector<int> maxTemp{ 17, 16, 9, 3, 1, 0, 0, 1, 9, 19, 15, 23 };
	vector<int> minTemp{ 10, 9, 5, -2, -3, -4, -6, -6, 1, 8, 8, 13 };
	int totalMax = max(maxTemp); // knows that maxtemp must always be equal or larger than mintemp
	int totalMin = min(minTemp);
	int ySpan = totalMax - totalMin; // no of degrees to span all of y-axis

	Open_polyline oplMax;
	for (int i = 0; i < maxTemp.size(); i++) {
		int temp = maxTemp[i];
		int xCoord = origo.x + ((i * 330) / 11);  // Can be simplified since 330/11 = 30, but is kept like this for readability !?
		int yCoord = origo.y - (210 * (temp - totalMin)) / ySpan;
		oplMax.add(Point{ xCoord, yCoord });
	}
	oplMax.set_color(Color::red);
	win.attach(oplMax);

	Open_polyline oplMin;
	for (int i = 0; i < minTemp.size(); i++) {
		int temp = minTemp[i];
		int xCoord = origo.x + ((i * 330) / 11);                      // Two lines equal to those for oplMax 
		int yCoord = origo.y - (210 * (temp - totalMin)) / ySpan;
		oplMin.add(Point{ xCoord, yCoord });
	}
	oplMin.set_color(Color::blue);
	win.attach(oplMin);

	win.wait_for_button();

	
};