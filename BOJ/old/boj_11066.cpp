#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, dp[501][501], v[501], sum[501][501];

int file(int dst, int pos){
    if(dst == pos) return 0;

    int &ret = dp[dst][pos];
    if(ret != -1) return ret;

    ret = 100000000;

    for (int i = dst; i < pos; i++)
    {
        ret = min(ret, file(dst, i) + file(i + 1, pos));
    }
    
    return ret += sum[dst][pos];
}

int main(){
    cin >> N;

    while(N--)
    {
        memset(dp, -1, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        
        int t;
        cin >> t;

        for (int i = 1; i <= t; i++)
        {
            cin >> v[i];
            sum[i][i] = v[i];
        }

        for (int i = 1; i <= t; i++)
        {
            for (int j = i + 1; j <= t; j++)
            {
                sum[i][j] = sum[i][j - 1] + v[j];
            }
        }

        cout << file(1, t) << endl;
    }
    
    return 0;
}