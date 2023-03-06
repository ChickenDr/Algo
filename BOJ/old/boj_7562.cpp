#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int v[301][301];
int movex[4] = {-2, -1, 1, 2}, movey[4][2] = {{-1, 1}, {-2, 2}, {-2, 2}, {-1, 1}};
bool visit[301][301];
queue<pair<int, pair<int, int> > > q;
int targetx, targety, N, resualt = 10000000;

void bfs(int x, int y)
{
    int cnt = 0;
    visit[x][y] = true;
    q.push(make_pair(cnt, make_pair(x, y)));

    while (!q.empty())   
    {
        pair<int, pair<int, int> > curr = q.front();
        q.pop();

        if(curr.second.first == targetx && curr.second.second == targety)
        {
            resualt = min(resualt, curr.first);
        }

        for (int i = 0; i < 4; i++)
        {
            int my = curr.second.second;
            my += movex[i];

            for (int j = 0; j < 2; j++)
            {
                int mx = curr.second.first;
                mx += movey[i][j];
                if(mx >= N || mx < 0 || my >= N || my < 0) continue;

                if(!visit[mx][my]){
                    visit[mx][my] = true;
                    q.push(make_pair(curr.first + 1, make_pair(mx, my)));
                }
            }
        }
    }
    
}

int main(){
    int t;
    cin >> t;
    
    while (t--)
    {
        cin >> N; 
        
        int kx, ky;
        cin >> kx >> ky;
        cin >> targetx >> targety;

        bfs(kx, ky);
        cout << resualt << endl;

        resualt = 100000000;
        memset(visit, false, sizeof(visit));
    }
    
    return 0;
}