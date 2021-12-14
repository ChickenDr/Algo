#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, map[101][101], t_map = [101][101];
int x_e[4] = {1, -1, 0, 0}, y_e[4] = {0, 0, 1, -1};
bool visit[101][101];

void dfs(int x, int y){
    visit[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int m_x = x + x_e;
        int m_y = y + y_e;
        if(m_x < 0 || m_x > n || m_y > m || m_y < 0 || visit[m_x][m_y]) continue;
        else dfs(mx, my);
    }
}

void malt(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            t_map[i][j] = map[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            
        }
    }
    
}

bool in_air(int x, int y){
    queue<pair<int, int> q;
}

int main(){
    cin >> n >> m;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    
    while(1){
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(!visit[i][j] && map[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }

        cnt = 0;
    }
    return 0;
}