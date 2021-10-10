#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> v(100001);
vector<long long> t_sum(100001);

long long divid(int i, int j) {
	if (i == j) return v[i] * v[i];

	int mid = (i + j) / 2;
	long long resualt = max(divid(i, mid), divid(mid+1, j));

	int l = mid;
	int r = mid + 1;
	long long t_min = min(v[l], v[r]);
	
	resualt = max(resualt, (t_sum[r] - t_sum[l-1]) * t_min);

	while (l > i || r < j) {
		if (r < j && (l == i || v[l -1] < v[r+1])) {
			r += 1;
			t_min = min(t_min, v[r]);
		}
		else {
			l -= 1;
			t_min = min(t_min, v[l]);
		}

		resualt = max(resualt, (t_sum[r] - t_sum[l - 1]) * t_min);
	}

	return resualt;
}

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	for (int x = 1; x <= N; x++) {
		t_sum[x] = t_sum[x-1] + v[x];
	}

	cout << divid(1, N);

	return 0;
}