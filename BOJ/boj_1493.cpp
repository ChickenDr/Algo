#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
vector<pair<int, int>> v;
int resualt = 0;

void subt(int l, int w, int h, int index){
    if (index == -1) {
        if ((long long)l * w * h > 0){
            cout << -1;
            exit(0);
        }
        return;
    }

    if(v[index].first > l || v[index].first > w || v[index].first > h || v[index].second == 0){
        subt(l, w, h, index - 1);
        return;
    }

    v[index].second--;
    resualt++;
    
    subt(l - v[index].first, w, h, index);
    subt(v[index].first, v[index].first, h - v[index].first, index);
    subt(v[index].first, w - v[index].first, h, index);
}

int main(){
    int l, w, h, cube;
    cin >> l >> w>> h;
    cin >> cube;
    for (int i = 0; i < cube; i++)
    {
        int tmp, cnt;
        long long vol;
        cin >> tmp >> cnt;
        v.push_back(make_pair(pow(2, tmp), cnt));
    }

    subt(l, w, h, cube - 1);
    
    cout << resualt;
    return 0;
}