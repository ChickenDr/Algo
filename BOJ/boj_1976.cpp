#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, parent[201], path[1001];

int find(int n){
    if(parent[n] < 0) return n;
    parent[n] = find(parent[n]);
    return parent[n];
}

void merge(int v1, int v2){
    v1 = find(v1);
    v2 = find(v2);
    if(v1 == v2) return;
    parent[v2] = v1;
}

int main(){
    cin >> n;
    cin >> m;

    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;

            if(tmp) merge(i, j);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> path[i];
    }

    bool flag = false;
    for (int i = 2; i <= m; i++)
    {
        if(find(path[1]) != find(path[i])){
            flag = true;
            break;
        }
    }
    
    if(flag) cout << "NO";
    else cout << "YES";
    
    return 0;
}