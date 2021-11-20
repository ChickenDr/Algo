#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
int N, dp[100001][4];

int zoo(int x, int dst){
    if(dst < 0) return 0;
    if(dp[dst][x]) return dp[dst][x];

    if (x == 0) dp[dst][0] = (zoo(0, dst - 1) + zoo(1, dst - 1) + zoo(2, dst - 1)) % 9901;
    else if (x == 1) dp[dst][1] = (zoo(0, dst - 1) + zoo(2, dst - 1)) % 9901;
    else if (x == 2) dp[dst][2] = (zoo(0, dst - 1) + zoo(1, dst - 1)) % 9901;

    return dp[dst][x];
}

int main(){
    cin >> N;
    dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;

    cout << (zoo(0, N) + zoo(1, N) + zoo(2, N)) % 9901;
    return 0;
}