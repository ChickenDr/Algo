#include <iostream>
#include <cstring>

using namespace std;

int N, v[16][16], dp[16][1 << 16];

int solve(int x, int dst){
    if(dst == (1 << N) - 1){
        if(v[x][0] != 0) return v[x][0];
        return 900000000;
    }

    int &res = dp[x][dst];
    if(res) return res;

    res = 900000000;
    for (int i = 0; i < N; i++)
    {
        if(dst & (1 << i) || v[x][i] == 0) continue;

        res = min(res, solve(i, (dst | (1 << i))) + v[x][i]);
    }

    return res;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }
    
    cout << solve(0, 1);
    
    return 0;
}