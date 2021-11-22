#include <iostream>
#include <algorithm>

using namespace std;
int N, K;
long long dp[1001][1001], d = 10007;

int sum(int dst, int x){
    if(dst == 1) return 10 - x;
    if(dp[dst][x]) return dp[dst][x];

    int tmp = 0;
    for (int i = x; i <= 9; i++)
    {
        tmp += sum(dst - 1, i);
        tmp %= d;
    }
    dp[dst][x] = tmp;

    return dp[dst][x];
}

int main(){
    cin >> N;
    
    cout << sum(N, 0);

    return 0;
}