#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, dp[16], v[16][2];

int solve(int dst)
{
    if(dst >= N + 1) return 0;

    int &ret = dp[dst];
    if(ret != -1) return ret;

    int next = dst + v[dst][0];
    int work = 0, nowork = 0;
    if(next <= N + 1)
    {
        work = solve(next) + v[dst][1];
    }
    nowork = solve(dst + 1);
    return ret = max(work, nowork);
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &v[i][0], &v[i][1]);
    }
    
    cout << solve(1) << endl;
    return 0;
}