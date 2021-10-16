#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}


int main(){
    vector<pair<int,int>> v;
    vector<int> resualt(1001);
    int tmp = 0, N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int d, w;
        cin >> d >> w;
        v.push_back(make_pair(d, w));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
    {
        if(resualt[v[i].first] != 0){
            for (int j = v[i].first; j > 0; j--)
            {
                if(resualt[j] < v[i].second)
                {
                    resualt[j] = v[i].second;
                    break;
                }
            }
        }
        else{
            resualt[v[i].first] = v[i].second;
        }
    }
    
    for (int i = 1; i <= 1000; i++)
    {
        tmp += resualt[i];
    }

    cout << tmp;
    
    return 0;
}