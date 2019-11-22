// Example program GUI_1, MyWindow.cpp, simple GUI elements  - commented
#include "GUI.h"
#include "Graph.h"
#include "MyWindow.h"
using namespace Graph_lib;
// sorry for magic numbers and non-scalable layout
MyWindow::MyWindow(Point topLeft, int w, int h, const string& title) : Window{ topLeft, w, h, title },
	start_button{ Point{10, 10}, 70, 20, "Start", cb_start },
	quit_button{ Point{x_max() - 80, 10}, 70, 20, "Quit", cb_quit },
	end_button{ Point{10, 40}, 70, 20, "End", cb_end },
	name(title),
	colorMenu{ Point{x_max() - 80, 40}, 70, 20, Menu::vertical, "color" },
	noOfDiscs{ Point{160, 10}, 50, 20, "discs"},
	radius{ Point{130, 40}, 80, 20, "radius"} 
{
	attach(start_button);
	attach(quit_button);

	colorMenu.attach(new Button{ Point{0, 0}, 0, 0, "red", cb_red });
	colorMenu.attach(new Button{ Point{0, 0}, 0, 0, "blue", cb_blue });
	colorMenu.attach(new Button{ Point{0, 0}, 0, 0, "green", cb_green });
	attach(colorMenu); colorMenu.hide();
	attach(end_button); end_button.hide();
	attach(noOfDiscs); noOfDiscs.hide();
	attach(radius); radius.hide();
}
void MyWindow::start() {
	cout << name + ": start called\n";
	colorMenu.show();
	end_button.show();
	noOfDiscs.show();	
	radius.show();
}
void MyWindow::end() {
	cout << name + ": end called\n";
	colorMenu.hide();
	end_button.hide();
}
void MyWindow::cb_start(Address, Address win) { reference_to<MyWindow>(win).start(); }
void MyWindow::cb_quit(Address, Address win) { reference_to<MyWindow>(win).quit(); }
void MyWindow::cb_red(Address, Address win) { reference_to<MyWindow>(win).red_pressed(); }
void MyWindow::cb_blue(Address, Address win) { reference_to<MyWindow>(win).blue_pressed(); }
void MyWindow::cb_green(Address, Address win) { reference_to<MyWindow>(win).green_pressed(); }
void MyWindow::cb_end(Address, Address win) { reference_to<MyWindow>(win).end(); }

void MyWindow::red_pressed() {
	cout << name + ": red pressed\n";
	drawDiscs(Color::red);
};
void MyWindow::blue_pressed() {
	cout << name + ": blue pressed\n";
	drawDiscs(Color::blue);
};
void MyWindow::green_pressed() {
	cout << name + ": green pressed\n";
	drawDiscs(Color::green);
};

void MyWindow::drawDiscs(Color color) {
	cout << name + ": drawDisc uses number entered in input-field discs\n";
	int n = noOfDiscs.get_int();
	string radi = "";
	for (int i = 0; i < n; i++) {
		int r = 1 + rand() % 40;
		radi += "r=" + to_string(r) + " ";
		discs.push_back(new Circle{ Point{10 + (rand() % (x_max() - 10)),
										  100 + (rand() % (y_max() - 60))}, r});
		discs[discs.size() - 1].set_fill_color(color);
		attach(discs[discs.size() - 1]);
	}
	radius.put(radi);
	redraw();
}