#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visit[20001], flag = false;
int color[20001];
vector<int> tree[20001];

void dfs(int curr, int pre){
    visit[curr] = true;

    for (int i = 0; i < tree[curr].size(); i++)
    {
        if(!visit[tree[curr][i]])
        {
            if(pre == 1)
            {
                color[tree[curr][i]] = 2;
                dfs(tree[curr][i], 2);
            }
            else if(pre == 2)
            {
                color[tree[curr][i]] = 1;
                dfs(tree[curr][i], 1);
            }
        }
        else if(color[tree[curr][i]] == color[curr])
        {
            flag = true;
            return;
        }
    }
}

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        int v, e;
        cin >> v >> e;

        for (int i = 0; i < e; i++)
        {
            int from, to;
            cin >> from >> to;
            from--; to--;
            
            tree[from].push_back(to);
            tree[to].push_back(from);
        }

        for (int i = 0; i < v; i++)
        {
            if (!visit[i])
            { 
                color[i] = 1;
                dfs(i, 1);
            }
        }

        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;

        flag = false;

        for (int i = 0; i < v; i++)
        {
            tree[i].clear();
        }
        
        memset(visit, false, sizeof(visit));
        memset(color, 0, sizeof(color));
    }
    
    return 0;
}