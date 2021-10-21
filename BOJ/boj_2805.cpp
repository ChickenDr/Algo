#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    vector<int> v;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int tmp = *max_element(v.begin(), v.end());
 
    int l = 0, h = tmp;
    while (l + 1 < h) {
        int mid = (l + h) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (v[i] > mid) {
                sum += (v[i] - mid);
            }
        }

        if (sum >= M) {
            l = mid;
        }
        else {
            h = mid;
        }
    }

    cout << l;
    return 0;
}