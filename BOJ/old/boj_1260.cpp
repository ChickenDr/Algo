#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> v[10001];
vector<int> tmp;
queue<int> qu;
bool visit[10001];

void sortList(){
    for(int i=1; i <= M; i++)
        sort(v[i].begin(), v[i].end());
}

void bfs(int x){
    qu.push(x);
    visit[x] = true;

    while (!qu.empty())
    {
        int curr = qu.front();
        qu.pop();
        tmp.push_back(curr);
        
        for (int next : v[curr])
        {
            if (!visit[next])
            {
                visit[next] = true;
                qu.push(next);
            }
        }
    }
}

void dfs(int x){
    visit[x] = true;
    tmp.push_back(x);

    for (int next : v[x])
    {
        if (!visit[next])
        {
            dfs(next);
        }
    }
}

int main(){
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    sortList();

    dfs(V);
    for (int i = 0; i < tmp.size(); i++)
    {
        cout << tmp[i] << " " ;
    }
    cout << endl;

    fill_n(visit, sizeof(visit), false);
    tmp.clear();

    bfs(V);
    for (int i = 0; i < tmp.size(); i++)
    {
        cout << tmp[i] << " ";
    }
    
    return 0;
}