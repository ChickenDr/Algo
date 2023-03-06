#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N, v[200001], base = (1 << 10);
vector<ll> tree(2000000, 1);

void update(int index){
    while(index > 1){
        index /= 2;
        tree[index] = (tree[index * 2] * tree[index * 2 + 1]) % 1000000007;
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
        ll tmp = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            tmp += abs(v[j] - v[i]);
        }

        if(tmp != 0) tree[i + base] = tmp;
    }

    for (int i = 0; i < N; i++)
    {
        cout << tree[i + base] << " ";
    }

    for (int i = 1; i < N; i++)
    {
        update(i + base);
    }
    

    cout << tree[1];
    return 0;
}