#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M, v[2001];
int dp[2001][2001];

int solve(int start, int end)
{
    if(start >= end) return 1;

    int &ret = dp[start][end];
    if(ret != -1) return ret;

    if(v[start] != v[end]) return ret = 0;
    return ret = solve(start + 1, end - 1);
}

int main()
{
    memset(dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", solve(s, e));
    }
    
    return 0;
}