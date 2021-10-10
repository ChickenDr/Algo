#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int a, cnt = 1;
	vector<pair<int, int>> meet;
	cin >> a;

	for (int x = 0; x < a; x++) {
		int i, j;
		cin >> i >> j;
		meet.push_back(make_pair(i, j));
	}

	pair<int, int> min = *min_element(meet.begin(), meet.end(), [](auto i, auto j) {
			return i.second < j.second;
	});

	for(int x = 0; x < a; x++){
		if (min.second <= meet[x].first) {
			pair<int, int> tmp = meet[x];
			for (int i = 0; i < a; i++) {
				if (meet[i].first >= min.second && tmp.second > meet[i].second) {
					tmp = meet[i];
				}
			}
			min = tmp;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}