#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
string str;
int dp[2501][2501];
vector<int> v;

int solve(int start, int end){
    int &ret = dp[start][end];
    if(ret != -1) return ret;

    
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        v.push_back(str[i] - 'A');


    }

    return 0;
}