#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, M, max_t = 0;
    vector<int> v;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int tmp = *max_element(v.begin(), v.end());
    cin >> M;
    vector<int> tmp_max;

    for (int x = 0; x < N; x++) {
        int tmp = 0;
        for (int i = 0; i < N; i++)
        {
            if (v[i] > v[x]) {
                tmp += v[x];
            }
            else {
                tmp += v[i];
            }
        }
        if (tmp <= M) {
            tmp_max.push_back(v[x]);
        }
    }

    int l = 0, h = tmp;
    while (l + 1< h) {
        int mid = (l + h) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (v[i] > mid) {
                sum += mid;
            }
            else {
                sum += v[i];
            }
        }

        if (sum >= M) {
            h = mid;
        }
        else {
            l = mid;
        }
    }
    if (tmp_max.size() == 0) cout << l;
    else {
        cout << max(*max_element(tmp_max.begin(), tmp_max.end()), l);
    }
    return 0;
}