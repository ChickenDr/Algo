#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, T;
long long d = 1000000009, dp[100001][4];

long long sum(int x, int dst){
    if(dst < 0) return 0;
    if(x == dst) return 1;
    if(dp[dst][x]) return dp[dst][x];

    if (x == 1) dp[dst][1] = (sum(2, dst - 1) + sum(3, dst - 1)) % d;
    else if (x == 2) dp[dst][2] = (sum(1, dst - 2) + sum(3, dst - 2)) % d;
    else if (x == 3) dp[dst][3] = (sum(1, dst - 3) + sum(2, dst - 3)) % d;

    return dp[dst][x];
}

int main(){
    cin >> T;
    
    while(T--){
        cin >> N;
        cout << (sum(1, N) + sum(2, N) + sum(3, N)) % d << endl;
    }
    return 0;
}