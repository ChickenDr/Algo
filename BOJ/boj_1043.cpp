#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, parent[51], resualt = 0;
vector<int> p[51];
vector<int> t;

int find(int n){
    if(parent[n] < 0) return n;
    return parent[n] = find(parent[n]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    parent[b] = a;
}

int main(){
    memset(parent, -1, sizeof(parent));

    cin >> n >> m;
    
    int t_c;
    cin >> t_c;

    for (int i = 0; i < t_c; i++)
    {
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }

    for (int i = 1; i <= m; i++)
    {
        int party;
        cin >> party;

        int front, tmp;
        for (int j = 1; j <= party; j++)
        {
            if(j == 1){
                cin >> front;
                p[i].push_back(front);
            }
            else{
                cin >> tmp;
                p[i].push_back(tmp);
                merge(front, tmp);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << " ";
    }
    

    for (int i = 1; i <= m; i++)
    {
        bool flag = true;
        for (int j = 0; j < p[i].size(); j++)
        {
            if(!flag) break;
            for (int k = 0; k < t.size(); k++)
            {
                if(find(p[i][j]) == find(t[k])){
                    flag = false;
                    break;
                }
            }   
        }
        if(flag) resualt++;
    }
    
    cout << resualt;
    return 0;
}