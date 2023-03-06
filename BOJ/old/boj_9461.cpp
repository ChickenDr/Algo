#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T;
long long dp[105] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
vector<long long> v;

long long solve(int x){
    if(dp[x] > 0) return dp[x];

    return dp[x] = solve(x - 3) + solve(x - 2);;
}
    
int main(){
    solve(103);
    cin >> T;

    while (T--)
    {
        int tmp;
        cin >> tmp;

        v.push_back(dp[tmp]); 
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    
    
    return 0;
}