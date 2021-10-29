#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, K;
    cin >> N;
    
    cin >> K;
    
    int l = 1, h = K;
    while(l <= h){
        int mid = (l + h) / 2;
        int cnt = 0;
        
        for (int i = 1; i <= N; i++)
        {
            if(mid / i > N){
                cnt += N;
            }

            else{
                cnt += mid / i;
            }
        }
        
        if(cnt >= K){
            h = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}