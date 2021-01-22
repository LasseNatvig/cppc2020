// NordicLetters.cpp
// Thanks to NTNU student Erling Syversveen Lie for contributing with this code,
// it has been slighty modified by Lasse Natvig 

// *** Note!   This is so far only THE WINDOWS VERSION --- 
//  - we will provide code for macOS and linux at a later stage

// //*** These include files and using directive are needed if you are not using includefiles from the PPP-text book
// #include <iostream>
// #include <string>
// #include "stdlib.h"
// #include <fcntl.h>
// #include <io.h>
// #include <stdio.h>
// #include <Windows.h>
// #include <fstream>
// using namespace std;

// // These include files are needed for PPP graphichs project
// #include <Windows.h>
// #include "Graph.h"
// #include "Simple_window.h" 

// These include files are needed for a plain PPP text project

// Only include Windows.h for Windows builds
#ifdef _WIN32
#include <Windows.h>
#endif
#include "std_lib_facilities.h" 

int main(){
	#ifdef _WIN32
    SetConsoleOutputCP(1252); // Needed for Norwegian letters (Windows)
    SetConsoleCP(1252); // Makes printing �, �, �, �, � and � possible. 
		// Remember to set file encoding to Nordic (ISO 8859-10)
		// note modified line 30 and new line 31 in Makefile to avoid encoding-warnings
	#endif

    string fileString{""};
    cout << "Hva vil du skrive til filen?\nPr�v gjerne ogs� Nordiske bokstaver som"
    << "f.eks '�', '�' og selvf�lgelig '���': ";
    cin >> fileString;
    ofstream ofs{"MyFile.txt"};
    ofs << "Denne teksten kommer direkte fra kildekode til fil: '������'\n\n";
    ofs << "N� kommer teksten du selv skrev inn i konsollen: \n" << fileString << "\n";
    ofs << "Det ser ut som at dette fungerte som �nsket ";
    ofs.close();
    cout << "\n__________________________________________________________________________\n";
    cout << "\nN� skal du f� tilbake innholdet i filen for � se at lesing fra fil fungerer: \n\n";
    ifstream ifs{"MyFile.txt"};
    while(getline(ifs,fileString)) {
        cout << fileString << "\n";
    }

    cout << "\n__________________________________________________________________________\n";
    string b = "Dette er en test p� � skrive til konsoll fra kildekode: '������������'\n";
    cout << b;

    cout << "\n__________________________________________________________________________\n";
    cout << "Siste test er direkte ekko fra input til output: \n";
    string consoleString{""};
    while(consoleString != "q"){
        cout << "Tast inn dine bokstaver, 'q' for � avslutte: ";
        cin >> consoleString;
        cout << consoleString << "\n";
    }
    return 0;
}
