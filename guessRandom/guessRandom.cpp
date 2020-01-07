 // guessRandom.cpp
#include "std_lib_facilities.h"

#define NDEBUG
#include<cassert>
using namespace std;

// Declares two functions that are defined below, after main()
int getGuess(int min, int max); // Ask the user for a number between min and max 
void printGuess(int guess, int secret, int count); // Gives feedback 

int main() {
	setlocale(LC_ALL, "Norwegian");  // Makes printing æ, ø, å, Æ, Ø and Å possible
	srand(static_cast<int>(time(nullptr))); // Sets a seed for random number generator given by current time. Comment out 
											// this statement if you want deterministic behaviour
	int secret = (rand() % 10) + 1; // sets secret number using rand()
	int guess = 0;   
	int count = 0;
	while (guess != secret) {
		guess = getGuess(1, 10);
		count++;
		printGuess(guess, secret, count);
	}
}

void printGuess(int guess, int secret, int count) {
	if (guess > secret) {
		cout << "Tallet er for stort" << endl;
	}
	else if (guess < secret) {
		cout << "Tallet er for lite" << endl;
	}
	else {
		cout << "Du har gjettet riktig (på " << count << " forsøk)" << endl;
	}
}

int getGuess(int min, int max) {
	// Ask the user for a number between min and max 
	int temp = 0;
	do {
		cout << "Gjett et tall mellom ";
		cout << min << " og " << max << ": ";
		cin >> temp;
		assert(temp != 0);
	} while (temp < min || temp > max);
	return temp;
}