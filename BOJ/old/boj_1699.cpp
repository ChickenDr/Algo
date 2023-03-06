#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N;
	vector<long long> dp(100001, 100001);

	cin >> N;
	dp[0] = 0;

	for (int x = 1; x <= N; x++) {
		for (long long i = pow(x, 2); i <= N; i++) {
			dp[i] = min(dp[i], dp[i - pow(x, 2)] + 1);
		}
	}

	cout << dp[N];
	return 0;
}