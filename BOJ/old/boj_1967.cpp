#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, resualt = -1;
bool visit[10001];
vector<pair<int, int>> tree[10001];

void dfs(int x, int weight){
    visit[x] = true;

    for (pair<int, int> p : tree[x])
    {
        if(!visit[p.first]){
            dfs(p.first, weight + p.second);
        }
    }

    resualt = max(resualt, weight);
    visit[x] = false;
}

int main(){
    cin >> n;
    n--;

    if(n == 0){
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        tree[from].push_back(make_pair(to, w));
        tree[to].push_back(make_pair(from, w));
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visit, false, sizeof(visit));
        dfs(i, 0);
    }
    
    cout << resualt;
    return 0;
}