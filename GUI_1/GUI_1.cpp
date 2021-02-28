 // Example program GUI_1, main.cpp, simple GUI elements  - commented

#include <Windows.h> // Only under windows-PC

#include "GUI.h"
#include "Graph.h"
#include "MyWindow.h"
using namespace Graph_lib;

int main() {
	// FreeConsole(); // to turn off console when starting debug.exe or release.exe (Only windows)
	MyWindow win1{ Point{550, 80}, 300, 400, "MyWindow 1 --" };
	MyWindow win2{ Point{1000, 80}, 400, 300, "MyWindow 2--" };
	return gui_main();  // starts GUI library main event loop
}