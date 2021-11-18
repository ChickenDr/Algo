#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, tree[3000001], base;
vector<pair<int, int>> v;

bool compare(pair<int, int> x, pair<int, int> i){
    return x.first < i.first;
}

int max_length(int l, int r, int n, int nl, int nr){
    if(r < nl || nr < l) return 0;
    if(l <= nl && nr <= r) return tree[n];
    int mid = (nl + nr) / 2;

    return max(max_length(l, r, n * 2, nl, mid), max_length(l, r, n * 2 + 1, mid + 1, nr));
}

void update(int index, int val) {
    tree[index] = val;
    while (index > 1)
    {
        index /= 2;
        tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
    }
}

int main(){
    cin >> N;
    base = (1 << 20);

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        v.push_back(make_pair(x, i));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
    {
        update(v[i].second + base, max_length(0, v[i].second, 1, 0, base - 1) + 1);
    }
    
    cout << tree[1];
    return 0;
}