#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, pare[100001], resualt = 0, cnt = 0;

int find(int n){
    if(pare[n] < 0) return n;
    return pare[n] = find(pare[n]);
}

bool merge(int v1, int v2){
    v1 = find(v1);
    v2 = find(v2);

    if(v1 == v2) return false;
    pare[v2] = v1;
    return true;
}

class Edge{
    public:
        pair<int, int> node;
        int dist;

        Edge(int from, int to, int w){
            this->node.first = from;
            this->node.second = to;
            dist = w;
        }
};

bool compare(Edge a, Edge b){
    return a.dist < b.dist;
}

int main(){
    cin >> n >> m;

    vector<Edge> v;

    for (int i = 0; i < m; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;

        v.push_back(Edge(from, to, w));
    }

    sort(v.begin(), v.end(), compare);
    
    memset(pare, -1, sizeof(pare));

    for (int i = 0; ; i++)
    {
        if (merge(v[i].node.first, v[i].node.second)){
            resualt += v[i].dist;
            if(++cnt == n - 2) break;
        }
    }

    cout << resualt << endl;
    return 0;
}