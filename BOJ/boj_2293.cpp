#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N, K, v[101], dp[10001], resualt = 0;

int main(){
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if(j - v[i] >= 0) dp[j] += dp[j - v[i]];
        }
    }
    
    cout << dp[K];
    return 0;
}