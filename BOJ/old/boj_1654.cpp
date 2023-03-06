#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    vector<long long> v(100001);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    long long h = *max_element(v.begin(), v.end());
    long long l = 1;
    long long resualt = 0;

    while (l <= h) {
        long long mid = (l + h) / 2, cnt = 0;

        for (int i = 0; i < N; i++) {
            long long tmp = v[i];
            cnt += v[i] / mid;
        }
        
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