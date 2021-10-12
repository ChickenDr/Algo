#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<long long> v(N+1);
	v[0] = 1;
	v[1] = 1;

	for (int i = 2; i < N+1; i++) {
		v[i] = ((2 * v[i - 2]) + v[i - 1]) % 10007;
	}
	cout << v[N];
	return 0;
}