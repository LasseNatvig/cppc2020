 // Example program GUI_1, main.cpp, simple GUI elements  - commented

// The following pragma turns off the console, under windows
// #pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "GUI.h"
#include "Graph.h"
#include "MyWindow.h"
using namespace Graph_lib;

int main() {
	srand(7); // Set a fixed initial seed, can be any number
	MyWindow win1{ Point{550, 80}, 300, 400, "MyWindow 1" };
	MyWindow win2{ Point{1000, 80}, 400, 300, "MyWindow 2" };
	return gui_main();
}