#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, L, tmp, cnt = 0;
	vector<int> w(1001);
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		w[tmp] = -1;
	}

	for (int x = 1; x < 1001; x++) {
		if (w[x] == -1) {
			for (int i = 0; i < L - 1; i++) {
				w[x]++;
			}
			x += L - 1;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}