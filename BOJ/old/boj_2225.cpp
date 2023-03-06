#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
int N, K;
long long dp[300][300], d = 1000000000;

int sum(int dst, int x){
    if(x <= 1) return (x == 1) ? 1 : 0;
    if(dp[dst][x]) return dp[dst][x];

    int tmp = 0;
    for (int i = 0; i <= dst; i++)
    {
        tmp += (sum(i, x - 1));
        tmp %= d;
    }
    
    dp[dst][x] = tmp;

    return dp[dst][x];
}

int main(){
    cin >> N >> K;
    
    cout << sum(N, K);

    return 0;
}