 // arguments.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 3) { // We expect 3 arguments: the program name, argument_1 and argument_2
		cerr << "Usage: " << argv[0] << " argument_1 argument_2" << endl;
		return 1;
	}
	vector <string> myArgs; // Not needed here, only if you like string better than Cstring
	for (int i = 1; i < argc; ++i) { // Remember argv[0] is the path to the program, we want from argv[1] onwards
		myArgs.push_back(argv[i]);
	}
	int i = 0;
	for (auto s : myArgs) {
		cout << "Argument no " << i << " is: " << myArgs[i] << endl;
		i++;
	}
	return 0;
}