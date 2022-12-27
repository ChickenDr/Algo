#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, dp[10000001];
vector<int> v;
int solve(int n){
    if(n <= 0) return 1000000000;
    if(n == 1) return 0;

    int &ret = dp[n];
    if(ret != -1) return ret;

    ret = solve(n - 1) + 1;
    if(n % 3 == 0) ret = min(ret, solve(n / 3) + 1);
    if(n % 2 == 0) ret = min(ret, solve(n / 2) + 1);

    return ret;
}

void find(int x)
{
	int next = x;
	int& ret = dp[x];

	cout << x << ' ';
	
	if (x == 1)  return;
	if (ret == solve(x - 1) + 1)
	{
		next = x - 1;
	}
	if (x % 3 == 0 && ret == solve(x / 3) + 1)
	{
		next = x / 3;
	}
	if (x % 2 == 0 && ret == solve(x / 2) + 1)
	{
		next = x / 2;
	}
	find(next);
}

int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));

    cout << solve(N) << endl;
    find(N);
    cout << endl;
    return 0;
}