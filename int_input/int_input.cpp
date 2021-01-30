//  int_input.cpp   
// Much inspired from PPP 10.7.

#include "std_lib_facilities.h"
int main() {

	//*****************************************************
	// case A)
	{
		constexpr int quit = 9;
		int choice = 0;
		while (choice != quit) {
			cout << "Menu:\n"
				"1: option A\n" 
				"2: option B\n"
				"3: option C\n"
				<< quit << ": Quit\n> ";
			cin >> choice;

			cout << "Option " << choice << " selected\n";
			// branch to right option and do it
		}
	}
	cout << endl;

	//*****************************************************
	// case B)
	{
		constexpr int quit = 9;
		int choice = 0;
		while (choice != quit) {
			cout << "Menu V2:\n"
				"1: option A\n" 
				"2: option B\n"
				"3: option C\n"
				<< quit << ": Quit\n> ";
			cin >> choice;

			if ((1 <= choice) && (choice <= 3)) { // By the way, && means logical AND, || is logical OR
				cout << "Option " << choice << " selected\n";
				// branch to right option and do it
				continue;
			}
			if (choice != quit) {
				cout << "sorry, try again\n";
			}
		}

	}
	cout << endl;

	//*****************************************************
	// case C)
	// Read chapter 10.7 about how to clean up code like this using functions
	{
		constexpr int quit = 9;
		int choice = 0;
		while (choice != quit) {
			cout << "Menu V3:\n"
				"1: option A\n" //
				"2: option B\n"
				"3: option C\n"
				<< quit << ": Quit\n> ";
			cin >> choice;
			if (cin) { // we got an integer since cin returns true, now check it
				if ((1 <= choice) && (choice <= 3)) {
					cout << "Option " << choice << " selected\n";
					// branch to right option and do it
					continue;
				}
				if (choice != quit) {
					cout << "sorry, try again\n";
				}
			}
			else if (cin.fail()) {
				cin.clear(); // set the state back to good
				cout << "not a number, try again\n";
				for (char c; (cin >> c) && !isdigit(c); ) // throw away non-digits 
					/* do nothing */;  // for loop terminates when first digit is read
				cin.unget(); // put digit back, so that we can read the number
			}
		}

	}

	cout << endl << "goodbye!" << endl;
	keep_window_open();
}