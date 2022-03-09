#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long v[100001];

long divid(long i, long j) {
    if (i == j) return 0;
    if (i + 1 == j) return v[i];

    long mid = (i + j) / 2;

    long resualt = max(divid(i, mid), divid(mid + 1, j));

    long l = mid;
    long r = mid;
    long h = v[mid];
    long w = 1;

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
    while (1)
    {
        long N;
        cin >> N;
        long tmp = -1;
        
        if(N == 0) break;

        for (int x = 0; x < N; x++) {
            cin >> v[x];
            tmp = max(tmp, v[x]);
        }

        cout << max(divid(0, N), tmp) << endl;

        memset(v, 0, sizeof(v));
    }
    
    return 0;
}