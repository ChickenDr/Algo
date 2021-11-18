#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, S, v[30], cnt = 0;

void backtrack(int i, int s){
        s += v[i];
        if (i >= N) return;
        if (s == S) cnt++;
        backtrack(i + 1, s - v[i]);
        backtrack(i + 1, s);
}

int main(){
    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    backtrack(0, 0);
    cout << cnt << endl;
    return 0;
}