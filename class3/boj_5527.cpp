#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, v[100001], dp[100001][2];

int solve(int dst, int stat)
{
    if(dst >= N) return 0;

    int &ret = dp[dst][stat];
    if(ret != -1) return ret;

    int cross = v[dst + 1] != v[dst] ? 1 : 0;

    int on = 0, ps = 0;
    if(!stat)
    {
        on = solve(dst + 1, 1) + cross;
    }
    ps = solve(dst + 1, stat) + cross;
    return ret = max(on, ps);
}

int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }
    
    return 0;
}