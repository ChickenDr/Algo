#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
const int MAX = 90000000;

using namespace std;

int n, m, result = 0, v1, v2, resualt = MAX;
bool visit[1001];
vector<int> dst(1001, MAX);
vector<pair<int, int>> tree[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijk(int start){
    dst[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int curr = pq.top().second;
        pq.pop();

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
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        tree[from].push_back(make_pair(to, w));
        tree[to].push_back(make_pair(from, w));
    }
    cin >> v1 >> v2;

    vector<int> start_dst;
    vector<int> v1_dst;
    vector<int> v2_dst;

    dijk(1);
    start_dst = dst;
    fill(dst.begin(), dst.end(), MAX);

    dijk(v1);
    v1_dst = dst;
    fill(dst.begin(), dst.end(), MAX);

    dijk(v2);
    v2_dst = dst;
    fill(dst.begin(), dst.end(), MAX);
    
    resualt = min(resualt, start_dst[v1] + v1_dst[v2] + v2_dst[n]);
    resualt = min(resualt, start_dst[v2] + v2_dst[v1] + v1_dst[n]);

    if(resualt >= MAX) cout << "-1";
    else cout << resualt;
    return 0;
}