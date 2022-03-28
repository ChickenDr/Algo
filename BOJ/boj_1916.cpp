#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
const int MAX = 1000000000;

using namespace std;

int n, m, v1, v2;
bool visit[1001];
vector<int> dst(1001, MAX);
vector<pair<int, int> > tree[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;

void dijk(int start){
    dst[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int curr;
        do
        {
            curr = pq.top().second;
            pq.pop();
        } while (!pq.empty() && visit[curr]);
        if(visit[curr]) break;

        visit[curr] = true;
        for (auto &p : tree[curr])
        {
            int next = p.first;
            int w = p.second;
            if(dst[next] > dst[curr] + w){
                dst[next] = dst[curr] + w;
                pq.push(make_pair(dst[next], next));
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        tree[from].push_back(make_pair(to, w));
    }
    cin >> v1 >> v2;
    dijk(v1);
    
    cout << dst[v2];
    return 0;
}