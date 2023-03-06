#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M, K, T;
int dp[301][301][301], map[301];

int solve(int dst, int yFrend, int yLetf)
{ 
    if(dst > N) return 0;

    int &ret = dp[dst][yFrend][yLetf];
    if(ret != -1) return ret;

    int wJoin = T <= map[dst] + yFrend ? 1 : 0;
    
    if(map[dst + 1] >= T) yFrend = 0;
    int yNeed = T - (map[dst + 1] + yFrend);

    ret = 0;
    if(yNeed > 0 && yNeed <= yLetf)
    {
        ret = max(ret, solve(dst + 1, yFrend + yNeed, yLetf - yNeed) + wJoin);
    }

    ret = max(ret, solve(dst + 1, yFrend, yLetf) + wJoin);
    return ret;
}

int main()
{
    memset(map, 0, sizeof(map));
    memset(dp, -1, sizeof(dp));

    cin >> N >> M >> K >> T;
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;

        for (int j = from; j < to; j++)
        {
            map[j]++;
        }
    }
    
    cout << solve(0, 0, K) << endl;
    return 0;
}