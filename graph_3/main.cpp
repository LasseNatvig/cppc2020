  // graph_3.cpp, an improvement of graph_2.cpp  
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

constexpr int xAxisSize = 330;
constexpr int yAxisSize = 210;
constexpr int maxMonthNo = 11;

int xCoord(Point origo, int i) {
	return(origo.x + ((i * xAxisSize) / maxMonthNo));
}
int yCoord(Point origo, int temp, int totalMin, int ySpan) {
	return(origo.y - (yAxisSize * (temp - totalMin)) / ySpan);
}

int main() {
	Point tl{ 100, 100 }; // tl is Top-Left corner of our window
	Point origo{ 40, 255 };
	Simple_window win(tl, 400, 300, " Example graph_3 ");
	Axis xa(Axis::x, origo, xAxisSize, maxMonthNo, "Month (August 2017 .. July 2018)");
	win.attach(xa); // attach xa to the window, win
	xa.set_color(Color::black);
	Axis ya(Axis::y, origo, yAxisSize, 7, "Celsius (-5 .. +25)");
	win.attach(ya); // attach ya
	ya.set_color(Color::black);

	// two vectors of max and min temperatures in Trondheim for august 2017 to july 2018
	vector<int> maxTemp{ 17, 16, 9, 3, 1, 0, 0, 1, 9, 19, 15, 23 };
	vector<int> minTemp{ 10, 9, 5, -2, -3, -4, -6, -6, 1, 8, 8, 13 };
	int totalMax = max(maxTemp); // knows that maxtemp must always be equal or larger than mintemp
	int totalMin = min(minTemp);
	int ySpan = totalMax - totalMin; // no of degrees to span all of y-axis

	Open_polyline oplMax;
	for (unsigned int i = 0; i < maxTemp.size(); i++) {
		oplMax.add(Point{ xCoord(origo,i), yCoord(origo, maxTemp[i], totalMin, ySpan) });
	}
	oplMax.set_color(Color::red);
	win.attach(oplMax);

	Open_polyline oplMin;
	for (unsigned int i = 0; i < minTemp.size(); i++) {
		oplMin.add(Point{ xCoord(origo,i), yCoord(origo, minTemp[i], totalMin, ySpan) });
	}
	oplMin.set_color(Color::blue);
	win.attach(oplMin);

	constexpr int backX = 100; 
	constexpr int backY = 50;
	constexpr int back_width = 150; 
	constexpr int back_height = 45;
	Rectangle background{ Point{backX, backY}, back_width, back_height }; // PPP 12.7.6
	background.set_fill_color(Color::yellow);
	win.attach(background);
	Text trd{ Point{110, 75}, "Trondheim - Norway" }; // hmmm, magic numbers ?
	trd.set_color(Color::dark_red);
	win.attach(trd);

	win.wait_for_button();
};