#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
bool visit[1000001];
int dp[1000001][2];
vector<int> tmp[1000001], tree[1000001];

void dfs(int curr){
    visit[curr] = true;
    for(int index = 0; index < tmp[curr].size(); index++){
        int next = tmp[curr][index];
        if(!visit[next]){
            tree[curr].push_back(next);
            dfs(next);
        }
    }
}

int sns(int curr, bool stat){
    int &ret = dp[curr][stat];
    if(ret != -1) return ret;

    if(!stat){
        ret = 0;
        for (int i = 0; i < tree[curr].size(); i++) {
            ret += sns(tree[curr][i], 1);
        }
    }else{
        ret = 1;
        for (int i = 0; i < tree[curr].size(); i++)
        {
            ret += min(sns(tree[curr][i], 0), sns(tree[curr][i], 1));
        }
    }
    
    return ret;
}

int main(){
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int from, to;
        cin >> from >> to;

        from--; to--;
        tmp[from].push_back(to);
        tmp[to].push_back(from);
    }
    
    dfs(0);
    
    memset(dp, -1, sizeof(dp));

    cout << min(sns(0, 0), sns(0, 1)) << endl;
    return 0;
}