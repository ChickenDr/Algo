#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, subset[1000001];

int find(int n){
    if(subset[n] < 0) return n;
    subset[n] = find(subset[n]);
    return subset[n];
}

void merge(int v1, int v2){
    v1 = find(v1);
    v2 = find(v2);
    if(v1 == v2) return;
    subset[v2] = v1;
}

int main(){
    cin >> n >> m;
    memset(subset, -1, sizeof(subset));

    for (int i = 0; i < m; i++)
    {
        int flag, v1, v2;
        scanf("%d %d %d", &flag, &v1, &v2);
        if(!flag){
            merge(v1, v2);
        }

        else{
            if(find(v1) == find(v2)) printf("YES\n");
            else printf("NO\n");
        }
    }
    
    return 0;
}