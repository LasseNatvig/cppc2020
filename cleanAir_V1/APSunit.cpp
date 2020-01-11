#include "APSunit.h"
const map<APSstate, string> stateColortextMap{ // for log-window
   {APSstate::unknown, "white"},
   {APSstate::planned, "white"},
   {APSstate::calibration, "light_gray"},
   {APSstate::booting, "mid_gray"},
   {APSstate::ok, "green"},
   {APSstate::warning, "yellow"},
   {APSstate::bad, "red"},
   {APSstate::malfunc, "black"},
   {APSstate::flaky, "cyan"},
};

 const map<string, Color>textToColorMap{
	 // for setting FLTK- color from text
	 {"white", Color::white},
	 {"light_gray", Color::light_gray},
	 {"mid_gray", Color::mid_gray},
	 {"green", Color::green},
	 {"yellow", Color::yellow},
	 {"red", Color::red},
	 {"black", Color::black},
	 {"cyan", Color::cyan},
 };

 int APSunit::sensorId = 0;

APSunit::APSunit(int sno, string name, string tag, Point loc, string descr)
	: location{ loc }, name{ name }, nameTag{ tag }, description{ descr },
	unitSerialNo{ sno }, 
	myId{ ++sensorId } // Note that the value of myId is not initialized 
		// by an argument but by the static class member sensorId
{
	display.push_back(new Rectangle{ loc, APSwidth, APSheigth });
	display[display.size() - 1].set_fill_color(
		textToColorMap.at(stateColortextMap.at(state)));
	display.push_back(new Text{ loc, name });
	display[display.size() - 1].set_color(Color::blue);
	static_cast<Text&>(display[display.size() - 1]).set_font_size(20); // downcasting using static_cast, since
		// display stores Shape& entries, Text is derived from Shape (child of Shape) and Shape does not have
		// the function set_font_size we must force the Shape& to act as a Text& using static_cast
};

void APSunit::attach(Graph_lib::Window & win) {
	for (int i = 0; i < display.size(); i++) {
		win.attach(display[i]);
	}
}
bool APSunit::set_description(const string s) {
	if (s.length() > maxDescriptionLength) {
		return false;
	}
	description = s;
	cout << "APS sensor " << myId << " " + name << " got new description:\n" << s;
	return true;
}
void APSunit::set_state(const APSstate s) { 
	state = s; // NOTE, the following is unsafe programming. We assume that the first shape added to display in the constructor is the rectangle
	display[0].set_fill_color(textToColorMap.at(stateColortextMap.at(s)));
}
ostream& operator<<(ostream& os, APSunit& unit) {
	return os << unit.get_myId() << " " << unit.get_name() << " " << unit.get_nameTag() << " " 
			<< stateColortextMap.at(unit.get_state());  
}
void initSensors(Vector_ref<APSunit>& allSensors, const string sensorsFileName) {
	ifstream sensFile{ sensorsFileName };
	if (sensFile.fail()) throw exception("Error opening file!");
	else { // Declare variables as local as possible
		string name; // the short name
		string tla; // nameTag. tla means Three Letter Abbreviation (TBF in Norwegian)
		int sno = 0; // serial number read from file, 0 terminates reading
		int xCoord = 0;
		int yCoord = 0;
		string description;
		sensFile >> sno;
		while (sno > 0) { // sno == 0 terminates loop
			sensFile >> name >> tla >> xCoord >> yCoord;
			getline(sensFile, description);
			allSensors.push_back(new APSunit{ sno, name, tla, 
									Point{ xCoord, yCoord }, description});
			cout << "APS sensor loaded: " << allSensors[allSensors.size() - 1] << endl;
			sensFile >> sno; // for next sensor
		}
	}
}
APSstate magicReadState() { // simulates reading data an determination of state
	return static_cast<APSstate>( rand() % ((static_cast<int>(APSstate::flaky) - 
										     static_cast<int>(APSstate::unknown)) + 1));
}
void updateSensors(Vector_ref<APSunit>& allSensors) {
	for (int i = 0; i < allSensors.size(); i ++) {
		APSstate s = magicReadState();
		allSensors[i].set_state(s);
		cout << allSensors[i] << endl; // debug 
	}
}

void APSunit::dummy() { // Dummy function using "unused variables" to avoid warnings
	// Here it is natural with unused variables since it is an incomplete program
	// It is a goal to let all example programs have zero warning
	APSunit dummy(0, "dummy", "XXX", Point{0,0}, "xxx");
	dummy.ozone = 0;
	dummy.particulateMatter = 0; // we assume thay can all be measured as a positive integer
	dummy.carbonMonoxide = 0;
	dummy.sulfurDioxide = 0;
	dummy.nitrousOxide = 0;
	dummy.location = Point{0,0};
	int dum = dummy.unitSerialNo;
	if (dum) { dum = dum+1; }
}