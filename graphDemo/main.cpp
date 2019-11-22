 #include "Graph.h"
#include "Simple_window.h" 

// class derived from Shape that does not have its own draw-line function
struct TestClass : Shape { // A very dumb class that always draws a red line (100,100) -- (200,200)
	TestClass() {
		Point p1{ 100,100 };
		Point p2{ 200,200 };
		add(p1);  // 
		add(p2);
		set_color(Color::red);
	}
};

int main() {
	using namespace Graph_lib;
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" }; 

	win.set_label("graphDemo.cpp");
	// The class Function is described in PPP 15.3
	Function sine{ sin, 0, 100, Point{ 20, 150 }, 1000, 50, 50 }; // sine curve	
		// plot sin() in the range [0:100) with (0,0) at (20,150) 
		// using 1000 points, scale x values *50, scale y values *50
	sine.set_color(Color::blue);
	win.attach(sine);
	win.wait_for_button();
	sine.set_color(Color::red);
	sine.set_style(Line_style::dash); 
	win.wait_for_button();
	Rectangle r{ Point{200,200}, 100, 100 };
	win.attach(r);
	r.set_fill_color(Color::yellow);
	win.wait_for_button();
	r.move(50, 50);
	win.wait_for_button();

	TestClass test;
	win.attach(test);
	win.wait_for_button(); // will draw all Shapes attached to win, and for the 
		// TestClass object named test the draw_lines function of Shape will be called

}