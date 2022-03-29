#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, level[101], result[101], ans = 1;
bool visited[101];
vector<int> tree[101];

void solve(int n)
{
    int tmp = 0;

    queue<int> q;
    visited[n] = true;
    q.push(n);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < tree[curr].size(); i++)
        {
            if(!visited[tree[curr][i]])
            {
                level[tree[curr][i]] = level[curr] + 1;
                q.push(tree[curr][i]);
                visited[tree[curr][i]] = true;
            }
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        if(i == n) continue;
        tmp += level[i];
    }
    result[n] = tmp;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;

        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    
    for (int i = 1; i <= N; i++)
    {
        memset(visited, false, sizeof(visited));
        memset(level, 0, sizeof(level));

        solve(i);
    }

    for (int i = 1; i <= N; i++)
    {
        if(result[ans] > result[i])
        {
            ans = i;
        }
    }
    
    cout << ans << endl;
    return 0;
}