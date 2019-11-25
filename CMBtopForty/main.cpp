 // CMBtopForty.cpp
// CMB problem TopForty 
#include <iostream>
#include<map>
#include<queue>
using namespace std;
int main(void) {
	cin.sync_with_stdio(false);
	int N = 0;
	int M = 0;
	int num = 0;
	long sum = 0;
	map<int, int> histo;  // kind of "histogramming"
	cin >> N >> M;
	while (N--) { // read into map
		cin >> num;
		histo[num]++;
	}

	struct histNum {
		int copies;
		int num;
		bool operator<(const histNum& rhs) const {
			if (copies == rhs.copies)
				return num < rhs.num;
			else
				return (copies < rhs.copies);
		}
	};
	priority_queue<histNum> pq;

	for (auto pair : histo) // Make priority queue, sorted the right way, see operator < in struct histNum above
		pq.push(histNum{ pair.second, pair.first }); // C++11  copies and num

	while (!pq.empty()) {
		if ((M--) > 0)
			cout << pq.top().num << ":" << pq.top().copies << endl;
		pq.pop();
	}
}