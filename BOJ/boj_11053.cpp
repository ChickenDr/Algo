#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, v[1001], dp[1001], res = -1;

int solve(int x){
    int &res = dp[x];
    if(res != -1) return res;
    
    res = 1;

    for (int i = x + 1; i <= N; i++)
    {
        if(v[x] < v[i]) res = max(res, solve(i) + 1); 
    }
    
    return res;
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= N; i++)
    {
        res = max(res, solve(i));
    }
    
    cout << res; 
    return 0;
}