#include <iostream>
#include <cstring>

using namespace std;

int N, back[10];
long long resualt = 0, dp[101][10][1 << 10];

long long solve(int pos, int pre, long long stat){
    if(pre < 0 || pre > 9) return 0;
    if(pos == N){
        if(stat == (1 << 10) - 1) return 1;
        else return 0;
    }

    long long &res = dp[pos][pre][stat];    
    if(res != -1) return res;

    res = 0;
    res = solve(pos + 1, pre + 1, (stat | (1 << pre + 1))) + solve(pos + 1, pre - 1, (stat | (1 << pre - 1)));

    return res % 1000000000;
}

int main(){
    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        memset(dp, -1, sizeof(dp));
        resualt += ((solve(1, i, 1 << i) % 1000000000));
    }
    
    cout << resualt % 1000000000;

    return 0;
}