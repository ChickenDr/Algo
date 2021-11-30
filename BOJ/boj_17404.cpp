#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, v[1001][4], dp[1001][4], res = 1000000, d = 1000000;


int solve(int dst, int x, int pre){
    if(dst == N){
        if(pre == x) return d;
        else return 0;
    }

    if(dp[dst][x] > 0) return dp[dst][x];

    int tmp = 1000000;
    for (int i = 0; i < 3; i++){
        if(x == i) continue;
        tmp = min(tmp, solve(dst + 1, i, pre) + v[dst][i]);
    }

    dp[dst][x] = tmp;
    
    return dp[dst][x];
}

int main(){
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }


    for(int i = 0; i < 3; i++){ 
        memset(dp, 0, sizeof(dp));

        res = min(res, solve(1, i, i) + v[0][i]);
    }

    cout << res;
    return 0;
}