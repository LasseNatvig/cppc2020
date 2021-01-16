// kattis problem, see lecture 3
#include <iostream>
#include <set>
using namespace std;
int main() {
    // cout << "test";
    int tests = 0;
    cin >> tests;
    while (tests-- > 0) {
        int visits = 0;
        set<string> cityNames;
        cin >> visits;
        while (visits-- > 0) {
            string name = "";
            cin >> name;
            cityNames.insert(name);
        }
        cout << cityNames.size() << endl;
    }
    return 0;
} 