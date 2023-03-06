#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, v[10001], dp[10001];
int solve(int x){
    if(x < 0) return 0;

    int &ret = dp[x];
    if(ret != -1) return ret;

    ret = max(ret, max(solve(x - 1), solve(x - 2)));
    ret = max(ret, solve(x - 2) + v[x]);
    ret = max(ret, solve(x - 3) + v[x] + v[x - 1]);

    return ret;
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }
    
    memset(dp, -1, sizeof(dp));

    cout << solve(N);

    return 0;
}