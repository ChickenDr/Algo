#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v(3000);
vector<int> cnt(3);

bool same(int N, int x, int y) {
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (v[i][j] != v[x][y]) {
				return false;
			}
		}
	}
	return true;
}

void divid(int N, int x, int y) {
 	if (same(N, x, y)) {
		cnt[v[x][y] + 1]++;
		return;
	}
	else {
	
 	//	if (N / 3 == 1) { 없어도 돌아감
		//	for (int i = x; i < x + N; i++) {
		//		for (int j = y; j < y + N; j++) {
		//			cnt[v[i][j] + 1]++;
		//		}
		//	}
		//	return;
		//}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divid(N / 3, x + (i * (N / 3)), y + (j * (N / 3))); 
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	for (int x = 0; x < N; x++) {
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			v[x].push_back(tmp);
		}
	}

	divid(N, 0, 0);

	cout << cnt[0] << endl;
	cout << cnt[1] << endl;
	cout << cnt[2];

	return 0;
} 