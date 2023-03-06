#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, w[31], bN, bw;
int dp[31][31 * 501];

void equalarm(int index, int weight)
{

    if (index > N) return;

    int &ret = dp[index][weight];
    if(ret != -1) return;

    ret = 1;

    equalarm(index + 1, weight + w[index]);
    equalarm(index + 1, weight);
    equalarm(index + 1, abs(weight - w[index]));
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> w[i];
    }

    memset(dp, -1, sizeof(dp));
    equalarm(0, 0);

    cin >> bN;
    for (int i = 0; i < bN; i++)
    {
        cin >> bw;
        if(bw > 30 * 500)
        {
            cout << "N ";
            continue;
        }
        if(dp[N][bw] == 1)
        {
            cout << "Y ";
        }
        else
        {
            cout << "N ";
        }
    }
    cout << endl;
    return 0;
}