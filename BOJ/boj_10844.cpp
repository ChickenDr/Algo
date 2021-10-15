#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp(1001, vector<int>(1001, -1));

int stair(int N, int digit){
    if(digit == -1 || digit > 9) return 0;
    if(N == 1) return 1;

    if(dp[N][digit] != -1) return dp[N][digit];
    
    dp[N][digit] = (stair(N - 1, digit - 1) + stair(N - 1, digit + 1)) % 1000000000;

    return dp[N][digit];
}

int main(){
    int N;
    long long result = 0;
    cin >> N;

    for (int i = 1; i <= 9; i++)
    {
        result += stair(N, i);
    }

    cout << result % 1000000000;
    return 0;
}