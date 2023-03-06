#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    vector<long long> v;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), less<long long>());

    long long h = *max_element(v.begin(), v.end());
    long long l = 1;
    long long resualt = 0;

    while (l <= h) {
        long long mid = (l + h) / 2, cnt = 0;
        long long tmp = v[0];

        for (int i = 0; i < N; i++) {
            if(v[i] - tmp >= mid){
                cnt++;
                tmp = v[i];
            }
        }
        
        if(cnt != 0) cnt++;

        if (cnt >= M) {
            if(resualt < mid) resualt = mid;
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    
    cout << resualt;
    return 0 ;
}