#include <iostream>
#include <algorithm>

using namespace std;

int N, v[600][600], dp[600][600], resualt = -1;

int solve(int dst, int x){
    if(dst > N || x > N) return 0;
    if (dp[dst][x]) return dp[dst][x];

    dp[dst][x] = max(solve(dst + 1, x) + v[dst][x], solve(dst + 1, x + 1) + v[dst][x + 1]);

    return dp[dst][x];
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << solve(1, 1);
    
    return 0;
}