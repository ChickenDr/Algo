#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    vector<int> A(1001);
    vector<int> dp(1001);
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    dp[1] = A[1];

    for (int i = 1; i <= N; i++)
    {
        for (int x = i; x <= N; x++)
        {
            if (A[i] >= A[x]) {
                dp[x] = max(A[x], dp[x]);
                continue;
            }
            dp[x] = max(A[x] + dp[i], dp[x]);
        }   
    }
    
    int resualt = *max_element(dp.begin(), dp.end());
    cout << resualt;
    
    return 0;
}