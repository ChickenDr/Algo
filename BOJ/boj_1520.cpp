#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, map[501][501], dp[501][501];
int m_x[4] = {1, -1, 0, 0}, m_y[4] = {0, 0, 1, -1};

int dfs(int x, int y){
    if(x == n - 1 && y == m - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = 0;

    for (int i = 0; i < 4; i++)
    {
        int tx = x + m_x[i];
        int ty = y + m_y[i];

        if(tx >= n || tx < 0 || ty >= m || ty < 0) continue;
        if(map[tx][ty] < map[x][y]) dp[x][y] += dfs(tx, ty);
    }

    return dp[x][y];
}


int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0);
    return 0;
}