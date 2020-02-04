// cleanAir_V1 (Several files)

// Only include Windows.h for Windows builds
#ifdef _WIN32
#include <Windows.h>
#endif
#include <Windows.h>
#include "Graph.h"
#include "Simple_window.h" 
#include "APSunit.h"

int main() try {
	#ifdef _WIN32
    SetConsoleOutputCP(1252); // Needed for Norwegian letters (Windows)
    SetConsoleCP(1252); // Makes printing æ, ø, å, Æ, Ø and Å possible. 
		// Remember to set file encoding to Nordic (ISO 8859-10)
		// note modified line 30 and new line 31 in Makefile to avoid encoding-warnings
	#endif
	cout << "cleanAir bruker C++ for et bedre miljø!\n\n";
	Point topLeft{ 200, 300 };
	Simple_window win{ topLeft, winWidth, winHeigth, cityWinTitle };
	cout << "... laster bykart\n";
	
	ifstream testFileExists{ cityFileName }; // opening file to check that it exists 
	if (!testFileExists) error("can't open input file ", cityFileName); // Remember that error (from PPP) will throw an exception
		// we use error here since it allows us to report also the filename for the file we tried to open
	Image cityMap{ Point{0,0}, cityFileName }; // The program hangs if file is not found, therefore we added the test above
	win.attach(cityMap);

	Vector_ref<APSunit> allSensors;
	cout << "... leser inn sensorer\n";
	initSensors(allSensors, sensorsFileName);
	for (int i = 0; i < allSensors.size(); i++) {
		allSensors[i].attach(win);
	}

	// for (auto sens: allSensors) sens->attach(win); 
	// exactly the same loop as above, as a one-liner. Uusing auto, more compact. The -> operator is lectured later

	win.wait_for_button();// debug

	cout << "... simulerer siste døgn\n";
	for (int hour = 0; hour < 24; hour++) {
		Text time{ Point{200, 200}, "Time: " + to_string(hour) + ":00h" };
		time.set_color(Color::dark_red);
		time.set_font(Font::helvetica_bold);
		time.set_font_size(30);
		win.attach(time);
		updateSensors(allSensors);
		win.wait_for_button(); // Since all the sensors were attached to the window every update will be displayed here 
		cout << "... Luftforurensingsstatus klokken " + to_string(hour) + " er vist (IKKE implementert enda)\n";
	}
}

	// test changing description 

catch (exception& e) {
	cerr << e.what();
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Unknown exception\n";
	keep_window_open();
	return 2;
}

