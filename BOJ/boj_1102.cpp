#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, P, v[16][16], e, cnt = 0, dp[1 << 16];

int solve(int cur, int stat){
    if(cur == P) return 0;

    int &res = dp[stat];
    if(res != -1) return res;

    res = 900000000;
    for (int i = 0; i < N; i++)
    {
        if(!(stat & (1 << i))) continue;
        for (int j = 0; j < N; j++)
        {
            if(i == j || (stat & (1 << j))) continue;
            res = min(res, solve(cur + 1, (stat | (1 << j))) + v[i][j]);
        }
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

    for (int i = 0; i < N; i++)
    {
        char a;
        cin >> a;
        if(a == 'Y') {
            e |= (1 << i);
            cnt++;
        }
    }

    cin >> P;
    
    memset(dp, -1, sizeof(dp));
    if(cnt >= P || P == 0) cout << 0;
    else if(cnt == 0) cout << -1;
    else cout << solve(cnt, e);
    
    return 0;
}