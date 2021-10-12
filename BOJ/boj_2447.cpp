#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> v;

void fill(int N) {
	for (int i = 0; i < N; i++) {
		vector<char> tmp;
		for (int k = 0; k < N; k++) {
			tmp.push_back(' ');
		}
		v.push_back(tmp);
	}
}

void divid(int N, int x, int y) {
	if (N == 1) {
		v[x][y] = '*';
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				continue;
			}
			divid(N / 3, x + (i * (N / 3)), y + (j * (N / 3)));
		}
	}
	return;
}
int main() {
	int N;
	cin >> N;

	fill(N);
	divid(N, 0, 0);

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cout << v[i][k];
		}
		cout << endl;
	}
	return 0;
}