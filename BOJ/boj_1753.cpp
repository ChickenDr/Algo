#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
const int MAX = 100000000;

using namespace std;


int V, E, start;
vector<int> dst(20001, MAX);
vector<pair<int, int>> tree[20001];
bool visit[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijk(int x){
    dst[x] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int curr;
        do{
            curr = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visit[curr]);

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
    cin >> V >> E;
    cin >> start;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back(make_pair(v, w));
    }
    
    dijk(start);
    for (int i = 1; i <= V; i++)
    {
        if(dst[i] == MAX) printf("INF\n");
        else printf("%d\n", dst[i]);
    }   
    return 0;
}