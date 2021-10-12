#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int mx, my, cnt = 0;

void divid(int N, int x, int y) {
	if (N == 1) {
		if (x == mx && y == my) {
			cout << cnt;
			exit(0);
		}
		else {
			cnt++;
			return;
		}
	}

	else if(mx >= x && mx <= x + N) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				divid(N / 2, x + (i * (N / 2)), y + (j * (N / 2)));
			}
		}
	}

	else {
		cnt += N * N;
	}
}

int main() {
	int N;
	cin >> N >> mx >> my;

	N = pow(2, N);
	divid(N, 0, 0);

	return 0;
}