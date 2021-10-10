#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.first < b.first;
}

int main() {
	int N;
	vector<pair<int, int>> v;

	cin >> N;

	for (int x = 0; x < N; x++) {
		int i, j;
		cin >> i >> j;
		v.push_back(make_pair(i, j));
	}

	sort(v.begin(), v.end(), compare);
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v[0].second);

	for (int i = 1; i < N; ++i) {
		if (pq.top() <= v[i].first) {
			pq.pop();
			pq.push(v[i].second);
		}
		else {
			pq.push(v[i].second);
		} 
	}

	cout << pq.size();
	return 0;
}