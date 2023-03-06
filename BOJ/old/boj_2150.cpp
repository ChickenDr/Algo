#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 100001

using namespace std;

vector<int> node[10001];
vector<vector<int>> scc;
stack<int> sk;
int V, E, id = 0, sccIndex[MAX], d[MAX];

bool compare(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

int scc_dfs(int x){
    d[x] = ++id;
    sk.push(x);

    int parent = d[x];
    for (int i = 0; i < node[x].size(); i++)
    {
        int y = node[x][i];
        if (d[y] == 0) parent = min(parent, scc_dfs(y));
        else if(!sccIndex[y]) parent = min(parent, d[y]);
    }

    if (parent == d[x])
    {
        vector<int> tmp;
        int index = scc.size() + 1;
        while (1)
        {
            int t = sk.top();
            sk.pop();
            tmp.push_back(t);
            sccIndex[t] = index;
            if(t == x) break;
        }
        sort(tmp.begin(), tmp.end());
        scc.push_back(tmp);
    }
    return parent;
}

int main(){
    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int v, e;
        cin >> v >> e;
        node[v].push_back(e);
    }

    for (int i = 1; i <= V; i++)
    {
        if(d[i] == 0) scc_dfs(i);
    }

    sort(scc.begin(), scc.end(), compare);
    cout << scc.size() << endl;

    for (int  i = 0; i < scc.size(); i++)
    {   
        for (int j = 0; j < scc[i].size(); j++)
        {
            cout << scc[i][j] << " ";
        }
        cout << -1 << endl;
    }

    return 0;
}