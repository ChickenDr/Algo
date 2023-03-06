#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int n, m, mx[4] = { 1, -1, 0, 0 }, my[4] = { 0, 0, 1, -1 }, resualt[1001][1001];
vector<string> map;
bool visit[1001][1001][2];
queue<pair<pair<int, int>, bool> > q; 

int bfs(){
    visit[0][0][0] = true;
    q.push(make_pair(make_pair(0, 0), false));
    resualt[0][0] = 1;

    while(!q.empty()){
        int q_size = q.size();

        pair<pair<int, int>, bool> curr = q.front();
        q.pop();

        int x = curr.first.first, y = curr.first.second, wall = curr.second;
        if (x == n - 1 && y == m - 1) return resualt[n - 1][m - 1];
            
        for (int i = 0; i < 4; i++)
        {
            if(x + mx[i] >= n || x  + mx[i] < 0 || y + my[i] >= m || y + my[i] < 0) continue;

            if(!visit[x + mx[i]][y + my[i]][wall] && map[x + mx[i]][y + my[i]] == '0'){
                visit[x + mx[i]][y + my[i]][wall] = true;
                resualt[x + mx[i]][y + my[i]] = resualt[x][y] + 1;
                q.push(make_pair(make_pair(x + mx[i], y + my[i]), wall));
            }

            else if(!wall && !visit[x + mx[i]][y + my[i]][1] && map[x + mx[i]][y + my[i]] == '1'){
                visit[x + mx[i]][y + my[i]][1] = true;
                resualt[x + mx[i]][y + my[i]] = resualt[x][y] + 1;
                q.push(make_pair(make_pair(x + mx[i], y + my[i]), true));
            }
        }
    }
    return -1;
}
int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        map.push_back(tmp);
    }
    
    cout << bfs();
    return 0;
}