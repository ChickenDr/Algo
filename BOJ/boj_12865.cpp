#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, K;
    vector<pair<int, int>> v;
    vector<vector<int>> dp(101, vector<int>(100001));

    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int w, p;
        cin >> w >> p;
        v.push_back(make_pair(w, p));
    }

    for (int i = 1; i <= N; i++)
    {
        for (int x = 1; x <= K; x++)
        {
            dp[i][x] = dp[i - 1][x];
            if (x - v[i-1].first >= 0) {
                dp[i][x] = max(dp[i][x], dp[i - 1][x - v[i-1].first] + v[i-1].second);
            }
        }
    }

    cout << dp[N][K] << endl;
    return 0;
}