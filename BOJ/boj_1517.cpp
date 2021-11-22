#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, v[2000000], tmp[2000000];
long long resualt = 0;

void mergesort(int l, int r){
    if(l >= r) return;

    int mid = (l + r) / 2;

    mergesort(l, mid);
    mergesort(mid+1, r);

    int i=l, j=mid+1, k= l;
    long long cnt = 0;
    
    for(;k<=r;++k){
        if(j > r ){
            tmp[k] = v[i++];
            resualt += cnt;
        }
        else if(i > mid) {
            tmp[k] = v[j++];
            cnt++;
        }
        else if(v[i] <= v[j]) {
            tmp[k] = v[i++];
            resualt += cnt;
        } 
        else {
            tmp[k] = v[j++];
            cnt++;
        }
    }

    for(i= l;i<=r;++i) v[i] = tmp[i];
}

int main(){
    cin >> N;
    int base = (1 << 20);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    mergesort(0, N-1);

    cout << resualt;
    
    return 0;
}