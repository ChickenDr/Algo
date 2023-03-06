#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> v(65);
vector<vector<int>> cnt(100);

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
		int tmp = v[x][y] < 1 ? 0 : 1;
		cout << tmp;
		return;
	}
	else {
		cout << "(";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				divid(N / 2, x + (i * (N / 2)), y + (j * (N / 2)));
			}
		}
		cout << ")";
	}
	
}

int main() {
	int N;
	cin >> N;

	for (int x = 0; x < N; x++) {
		string tmp;
		cin >> tmp;
		for (int i = 0; i < N; i++) {
			v[x].push_back(tmp[i] - '0');
		}
	}

	divid(N, 0, 0);
	return 0;
}