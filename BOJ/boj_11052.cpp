#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> p(1001);
	vector<int> dp(1001);

	for (int x = 1; x <= N; x++) {
		cin >> p[x];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int x = i; x <= N; x++)
		{
			dp[x] = max(dp[x], dp[x - i] + p[i]);
		}
		
	}
	
	cout << dp[N];

	return 0;
}