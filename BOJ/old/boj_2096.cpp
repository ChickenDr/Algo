#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, max_dp[3], min_dp[3], t[3];

void min_down(){
    int tmp[3];
    tmp[0] = min_dp[0], tmp[1] = min_dp[1], tmp[2] = min_dp[2];

    for (int i = 0; i < 3; i++)
    {
        if(i == 0) min_dp[i] = min(t[i] + tmp[0], t[i] + tmp[1]);
        else if(i == 1) min_dp[i] = min(t[i] + tmp[0], min(t[i] + tmp[1], t[i] + tmp[2]));
        else min_dp[i] = min(t[i] + tmp[1], t[i] + tmp[2]);

    }
}

void max_down(){
    int tmp[3];
    tmp[0] = max_dp[0], tmp[1] = max_dp[1], tmp[2] = max_dp[2];

    for (int i = 0; i < 3; i++)
    {
        if(i == 0) max_dp[i] = max(t[i] + tmp[0], t[i] + tmp[1]);
        else if(i == 1) max_dp[i] = max(t[i] + tmp[0], max(t[i] + tmp[1], t[i] + tmp[2]));
        else max_dp[i] = max(t[i] + tmp[1], t[i] + tmp[2]);

    }
}

int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> t[j];
        }

        if(i == 0) {
            max_dp[0] = t[0], max_dp[1] = t[1], max_dp[2] = t[2];
            min_dp[0] = t[0], min_dp[1] = t[1], min_dp[2] = t[2];
        }
        else {
            max_down();
            min_down();
        }
    }

    cout << max(max_dp[0], max(max_dp[1], max_dp[2])) << " " << min(min_dp[0], min(min_dp[1], min_dp[2]));
    return 0;
}