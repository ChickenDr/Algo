#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, K;
	vector<int> v(1);
	vector<int> dp(10001, 100001);

	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	dp[0] = 0;

	for (int x = 1; x <= N; x++) {
		for (int i = v[x]; i <= K; i++) {
			dp[i] = min(dp[i], dp[i - v[x]] + 1);
		}
	}
	cout << dp[K];
	return 0;
}