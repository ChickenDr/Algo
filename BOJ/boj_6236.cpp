#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M, max_sum = 0;
    vector<int> v(100001);
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
        max_sum += v[i];
    }

    int l = *max_element(v.begin(), v.end());

    int h = max_sum;
    while (l <= h) {
        int mid = (l + h) / 2, cnt = 0;
        long long sum = 0;

        for (int i = 1; i <= N; i++) {
            if(sum + v[i] > mid){
                cnt++;
                sum = v[i];
            }
            else{
                sum += v[i];
            }
        }
        
        if (cnt <= M) {
            h = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    
    cout << l;
    return 0 ;
}