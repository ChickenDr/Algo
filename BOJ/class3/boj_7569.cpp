#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, H, map[101][101][101], cnt = 1;
int mx[6] = {1, -1, 0, 0, 0, 0}, my[6] = {0, 0, 1, -1, 0, 0}, mh[6] = {0, 0, 0, 0, 1, -1};
bool visited[101][101][101];
queue<pair<int, pair<int, int> > > q;

bool fill()
{
    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(map[k][i][j] == 0)
                {
                    return false;
                }
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
            pair<int, pair<int, int> > curr = q.front();
            q.pop();

            for (int i = 0; i < 6; i++)
            {
                int th = curr.first + mh[i];
                int tx = curr.second.first + mx[i];
                int ty = curr.second.second + my[i];

                if(tx < 0 || ty < 0 || tx >= N || ty >= M || th < 0 || th >= H || visited[th][tx][ty] || map[th][tx][ty] == -1) continue;

                if(map[th][tx][ty] == 0)
                {
                    map[th][tx][ty] = 1;
                    q.push(make_pair(th, make_pair(tx, ty)));
                    visited[th][tx][ty] = true;
                }
            }
        }
        if(fill()) return;
        cnt++;
    }
}

int main(){
    cin >> M >> N >> H;

    for (int k = 0; k < H; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> map[k][i][j];
                if(map[k][i][j] == 1) 
                {
                    visited[k][i][j] = true;
                    q.push(make_pair(k, make_pair(i, j)));
                }
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