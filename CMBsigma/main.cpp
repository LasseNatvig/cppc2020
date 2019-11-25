 // CMBsigma.cpp
// CMB problem Sigma Unique 
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(void) {
	cin.sync_with_stdio(false);
	int N = 0;
	int num = 0;
	long sum = 0;
	set<int> allNums;
	cin >> N;
	while (N--) {
		cin >> num;
		if (allNums.find(num) == allNums.end()) {
			allNums.insert(num);
			sum += num;
		}
	}
	cout << sum << endl;
}