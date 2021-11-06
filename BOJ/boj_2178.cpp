#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int N, M, v[101][101];
queue<pair<int, int>> qu;
bool visit[101][101];

int bfs(){
    int level = 0;
    qu.push(make_pair(1, 1));
    visit[1][1] = true;

    while (!qu.empty())
    {
        int quSize = qu.size();
        for (int i = 0; i < quSize; i++)
        {
            pair<int, int> curr = qu.front();
            if (curr.first == N && curr.second == M)
            {
                return level;
            }
            
            int x = curr.first, y = curr.second;
            qu.pop();
            
            vector<pair<int, int>> tmp;
            if(y + 1 <= M && v[x][y + 1] && !visit[x][y + 1]) tmp.push_back(make_pair(x, y + 1));
            if(y - 1 >= 1 && v[x][y - 1] && !visit[x][y - 1]) tmp.push_back(make_pair(x, y - 1));
            if(x + 1 <= N && v[x + 1][y] && !visit[x + 1][y]) tmp.push_back(make_pair(x + 1, y));
            if(x - 1 >= 1 && v[x - 1][y] && !visit[x - 1][y]) tmp.push_back(make_pair(x - 1, y));
        
            for (int i = 0; i < tmp.size(); i++)
            {
                visit[tmp[i].first][tmp[i].second] = true;
                qu.push(tmp[i]);
            }
        }
        level++;
    }

    return -1;
}


int main(){
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= M; k++)
        {
            scanf("%1d", &v[i][k]);
        }
    }

    cout << bfs() + 1;
    
    return 0;
}