#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, sub[101], resualt = 0;

int find(int n){
    if(sub[n] < 0) return n;
    return sub[n] = find(sub[n]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    sub[b] = a;
}

int main(){
    memset(sub, -1, sizeof(sub));

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        merge(from, to);
    }

    for (int i = 2; i <= n; i++)
    {
        if(find(i) == find(1)) resualt++;
    }
    cout << resualt;
    return 0;
}