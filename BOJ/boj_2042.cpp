#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using ll = long long;
using namespace std;

ll N, M, K;
ll v[4000001], base;

ll sum(int s, int e) {
	ll ans = 0;
	while (s <= e) {
		if (s % 2 == 1) ans += v[s];
		if (e % 2 == 0) ans += v[e];
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ans;
}

void update(ll index, ll val){
    index += base;
    v[index] = val;
    while (index > 1)
    {
        index /= 2;
        v[index] = v[index * 2] + v[(index * 2) + 1];
    }
}

void construct(){
    for (ll i = base; i > 0; --i)
    {
        v[i] = v[i * 2] + v[i * 2 + 1];
    }    
}

int main(){
    cin >> N >> M >> K;
    base = N * 2;

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i + base];
    }

    construct();
    
    ll a, b, c;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;
        if(a == 1){
            update(b, c);
        }
        else if(a == 2){
            cout << sum(b + base, c + base) << endl;
        }
    }
    return 0;
}