#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, w[10001], dp[10001][2], picked[10001];
bool visit[10001];
vector<int> tree [10001], v[10001], ans;

void dfs(int pos)
{
    visit[pos] = true;

    for(int i = 0; i < v[pos].size(); i++)
    {
        int next = v[pos][i];

        if(!visit[next]){
            tree[pos].push_back(next);
            dfs(next);
        }
    }
}

void track(int now, int include){
	if(include){
		ans.push_back(now);
		for(int i=0; i<tree[now].size(); i++){
			int nxt = tree[now][i];
			track(nxt, 0);
		}
	}
	else{
		for(int i=0; i<tree[now].size(); i++){
			int nxt = tree[now][i];
			track(nxt, picked[nxt]);
		}
	}
}

int answer(int pos, bool stat)
{
    int &ret = dp[pos][stat];
    if(ret != -1) return ret;

    if (stat)
    {
        int resualt = 0;
        for (int i = 0; i < tree[pos].size(); i++)
        {
            resualt += answer(tree[pos][i], 0);
        }
        return ret = resualt + w[pos];
    }
    else
    {
        int resualt = 0;
        for (int i = 0; i < tree[pos].size(); i++)
        {
            int n1 = answer(tree[pos][i], 0);
            int n2 = answer(tree[pos][i], 1);

            picked[tree[pos][i]] = (n1 < n2) ? 1 : 0;
            
            resualt += max(n1, n2);
        }
        return ret = resualt;
    }
}

int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        from--; to--;

        v[from].push_back(to);
        v[to].push_back(from);
    }

    dfs(0);

    int a = answer(0, 0);
    int b = answer(0, 1);

    (a < b) ? picked[0] = 1 : picked[0] = 0;
    
    track(0, picked[0]);
    
    cout << max(a, b) << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}