#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(100001);

int divid(int i, int j) {
    if (i == j) return 0;
    if (i + 1 == j) return v[i];

    int mid = (i + j) / 2;

    int resualt = max(divid(i, mid), divid(mid + 1, j));

    int l = mid;
    int r = mid;
    int h = v[mid];
    int w = 1;

    while (l > i || r < j) {

        if (r < j &&( i == l || v[l - 1] < v[r + 1])) {
            r += 1;
            h = min(h, v[r]);
        }

        else {
            l -= 1;
            h = min(h, v[l]);
        }

        resualt = max(resualt, ++w * h);
    }
    return resualt;
}

int main() {
    int N;
    cin >> N;

    for (int x = 1; x <= N; x++) {
        cin >> v[x];
    }

    cout << divid(1, N);
    return 0;
}