#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int pare[200001], M, N, resualt = 0, cnt = 0, m = 0;

int find(int n){
    if(pare[n] < 0) return n;
    return pare[n] = find(pare[n]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    pare[b] = a;

    return true;
}

class Edge{

public:
    pair<int, int> node;
    int dst;

    Edge(int from, int to, int w){
        node.first = from;
        node.second = to;
        dst = w;
    }
};

bool compare(Edge a, Edge b){
    return a.dst < b.dst;
}

int main(){
    while(1){    
        memset(pare, -1, sizeof(pare));
        m = 0, resualt = 0, cnt = 0;
        vector<Edge> v;

        cin >> N >> M;
        if(N == 0 && M == 0) break;

        for (int i = 0; i < M; i++)
        {
            int from, to, dst;
            cin >> from >> to >> dst;
            m += dst;
            v.push_back(Edge(from, to, dst));
        }

        sort(v.begin(), v.end(), compare);

        for (int i = 0; ; i++)
        {
            if(merge(v[i].node.first, v[i].node.second)){
                resualt += v[i].dst;
                if(++cnt == N - 1) break;
            }
        }

        cout << m - resualt << endl;
    }
    return 0;
}   