#include <iostream>
#include <algorithm>

using namespace std;
int N;
long long dp[1000001];

long long solve(int dst, int x, int cnt){
    if(x == 1) return 1;
    if(dp[x]) return dp[x];
    
    long long res = 200000000;
    for (int i = 3; i > 0; i--)
    {
        if(i == 1) res = min(res, cnt + solve(dst + 1, x - 1, cnt));
        else if(x % i == 0) res = min(res, cnt + solve(dst + 1, x / i, cnt));
    }
    
    dp[x] = res;
    return dp[x];
}

int main(){
    cin >> N;

    cout << solve(1, N, 0);
    return 0;

}