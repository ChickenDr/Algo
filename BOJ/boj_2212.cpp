#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, K, cnt = 0;
	vector<int> v;
	vector<int> range;

	cin >> N;
	cin >> K;
	if (K >= N) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), less<int>());

	for (int i = 1; i < N; i++) {
		range.push_back(v[i] - v[i-1]);
	}

	sort(range.begin(), range.end(), less<int>());
	for (int i = 0; i < N - K; i++) {
		cnt += range[i];
	}

	cout << cnt;
	return 0;
}