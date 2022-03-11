#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool visit[20001], finished[20001], flag = false;
vector<int> tree[20001];

void dfs(int curr){
    visit[curr] = true;

    for (int i = 0; i < tree[curr].size(); i++)
    {
        int next = tree[curr][i];
        cout << next + 1;

        if(visit[next])
        {
            if(!finished[next])
            {
                flag = true;
            }
        }
        else
        {
            dfs(next);
        }
    }

    finished[curr] = true;
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
        }

        dfs(0);

        if(flag) cout << "No" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}