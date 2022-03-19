#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int R, C, cnt = 1, mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
bool v[1501][1501], wV[1501][1501];
char map[1501][1501], tmap[1501][1501];
queue<pair<int, int> > q;
queue<pair<int, int> > Nq;
vector<pair<int, int> > bird;

bool bfs(int x, int y)
{
    v[x][y] = true;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        pair<int , int > curr = q.front();
        v[curr.first][curr.second] = true;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int tx = curr.first + mx[i];
            int ty = curr.second + my[i];

            if(tx < 0 || ty < 0 || tx >= R || ty >= C || v[tx][ty]) continue;

            if(map[tx][ty] == '.') q.push(make_pair(tx, ty));
            else if(map[tx][ty] == 'X' && !wV[tx][ty]) Nq.push(make_pair(tx, ty));
            else if(map[tx][ty] == 'L') return true;
        }
    }
    return false;
}

void melt()
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            tmap[i][j] = map[i][j];
        }
    }

    while (!Nq.empty())
    {
        pair<int, int > curr = Nq.front();
        wV[curr.first][curr.second] = true;
        Nq.pop();

        for (int i = 0; i < 4; i++)
        {
            int tx = curr.first + mx[i];
            int ty = curr.second + my[i];

            if(tx < 0 || ty < 0 || tx >= R || ty >= C || wV[tx][ty]) continue;

            if(tmap[tx][ty] == '.')
            {
                map[curr.first][curr.second] = '.';
            }
            else if(tmap[tx][ty] == 'X') Nq.push(make_pair(tx, ty));
        }
    }
}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 'X') Nq.push(make_pair(i, j));
            if(map[i][j] == 'L') bird.push_back(make_pair(i, j));
        }
    }

    while (1)
    {
        memset(wV, false, sizeof(wV));
        memset(v, false, sizeof(v));

        melt();

        // for(int i = 0; i < R; i++)
        // {
        //     for(int j = 0; j < C; j++)
        //     {
        //         cout << map[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        if(bfs(bird[0].first, bird[0].second))
        {
            cout << cnt << endl;
            break;
        }
        else
        {
            cnt++;
        }
    }
    return 0;
}