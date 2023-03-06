#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, level = 0, map[101][101], t_map[101][101];
int x_e[4] = {1, -1, 0, 0}, y_e[4] = {0, 0, 1, -1};
bool visit[101][101], a_visit[101][101], a_map[101][101];

void dfs(int x, int y){
    visit[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int m_x = x + x_e[i];
        int m_y = y + y_e[i];
        if(m_x < 0 || m_x > n || m_y > m || m_y < 0 || visit[m_x][m_y]) continue;
        else dfs(m_x, m_y);
    }
}

void melt(){
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
            if(map[i][j]){
                for (int k = 0; k < 4; k++)
                {
                    int m_x = i + x_e[k];
                    int m_y = j + y_e[k];

                    if(m_x < 0 || m_x > n || m_y > m || m_y < 0 || !a_map[m_x][m_y]) continue;
                    cnt++;
                }

                if(cnt >= 2){
                    map[i][j]--;
                }
            }
            cnt = 0;
        }
    }
    
}

void out_air(){
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    a_visit[0][0] = true;

    while(!Q.empty()){
        pair<int, int> curr = Q.front();
        Q.pop();

        int x = curr.first, y = curr.second;

        for (int k = 0; k < 4; k++)
        {
            int m_x = x + x_e[k];
            int m_y = y + y_e[k];

            if(m_x < 0 || m_x > n || m_y > m || m_y < 0 || a_visit[m_x][m_y] || map[m_x][m_y] > 0) continue;
            else{
                a_map[m_x][m_y] = true;
                a_visit[m_x][m_y] = true;
                Q.push(make_pair(m_x, m_y));
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    
    while(1){
        memset(visit, false, sizeof(visit));
        memset(a_map, false, sizeof(a_map));
        memset(a_visit, false, sizeof(a_visit));
        out_air();

        int cnt = 0;
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

        if (cnt == 0) break;
        
        level++;
        melt();
        cnt = 0;
    }

    cout << level;
    return 0;
}