#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, H, map[1001][1001], mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1}, cnt = 1;
bool visited[1001][1001];
queue<pair<int, int> > q;

bool fill()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(map[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            pair<int, int> curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int tx = curr.first + mx[i];
                int ty = curr.second + my[i];
                if(tx < 0 || ty < 0 || tx >= N || ty >= M || visited[tx][ty] || map[tx][ty] == -1) continue;

                if(map[tx][ty] == 0)
                {
                    map[tx][ty] = 1;
                    q.push(make_pair(tx, ty));
                    visited[tx][ty] = true;
                }
            }
        }
        if(fill()) return;
        cnt++;
    }
}

int main(){
    memset(visited, false, sizeof(visited));
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1) 
            {
                visited[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }
    if(fill()) 
    {
        cout << 0 << endl;
        return 0;
    }

    solve();
    
    if(fill()) cout << cnt << endl;
    else cout << -1 << endl;
    return 0;
}