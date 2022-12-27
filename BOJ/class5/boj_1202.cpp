#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, M;
vector<pair<int, int>> v;
vector<int> bag;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int w, p;
        cin >> w >> p;
        v.push_back(make_pair(w, p));
    }

    for (int i = 0; i < M; i++)
    {
        int tmp;
        cin >> tmp;
        bag.push_back(tmp);
    }
    
    sort(bag.begin(), bag.end());
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i].first)
    }
    
    
    return 0;
}