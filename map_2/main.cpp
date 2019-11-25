#include<iostream>
#include<map>
#include<string>
#include<utility>
using namespace std;

void print(map<string, double>& mp) {
	for (const auto& e : mp) {
		cout << e.first << " " << e.second << ", ";
	}
	cout << endl;
}

int main() {
	map<string, double> foodPrices;
	foodPrices["Milk"] = 20.50;
	foodPrices["Bread"] = 30.50;
	foodPrices["Orange"] = 22.99;
	foodPrices["Orange"] = 33.99;  // shows that it overwrites
	cout << foodPrices.size() << " " << foodPrices["Orange"] << endl;
	pair<string, double> tea{ "Tea", 10.49 };
	foodPrices.insert(tea); // two ways to insert
	foodPrices.insert({ "Coke", 20.67 });
	print(foodPrices);
	auto it = foodPrices.find("Bread");
	if (it != foodPrices.end()) {
		foodPrices.erase(it); // Bread found, erase by iterator it
	}
	foodPrices.erase("Coke");
	foodPrices.erase("Solo");  // erase on non-existing pair is harmless
	cout << foodPrices["Banana"] << endl; // NOTE, reading missing element inserts!
	print(foodPrices);


	cout << endl;
	try {
		cout << foodPrices.at("Milk") << endl;
		cout << foodPrices.at("milk") << endl;
		cout << foodPrices.at("melk") << endl;
	}
	catch (exception& e) {
		cerr << "Exception caught: " << e.what();
	}
	return 0;
}