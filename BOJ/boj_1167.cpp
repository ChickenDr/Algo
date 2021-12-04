#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, resualt = -1, max_node = -1, max_dst = -1;
vector<pair<int, int>> tree [100001];
bool visit[100001];

void dfs(int x, int cnt){
    visit[x] = true;

    if(max_dst < cnt){
        max_dst = cnt;
        max_node = x;
    }

    for (int i = 0; i < tree[x].size(); i++)
    {
        if(!visit[tree[x][i].first]){
            dfs(tree[x][i].first, cnt + tree[x][i].second);
        }
    }

    resualt = max(resualt, cnt);
    visit[x] = false;
}

int main(){
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int v;
        cin >> v;

        while(1){
            int to, w;
            cin >> to;
            if(to == -1) break;
            cin >> w;

            tree[v].push_back(make_pair(to, w));
        }
    }

    dfs(1, 0);
    resualt = -1;

    dfs(max_node, 0);
    cout << resualt;
    return 0;
}