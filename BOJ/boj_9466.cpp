#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0, t, N, v[100001];
bool visit[100001], finish[100001];

void dfs(int x){
    visit[x] = true;
    int next = v[x];
    int tmp = next;

    if(visit[next]){
        if(!finish[next]){
            while(tmp != x){
                tmp = v[tmp];
                cnt++;
            }
			cnt++;
        }
    }
    else{
        dfs(next);
    }
    finish[x] = true;
}

int main(){
    cin >> t;

    while(t--){
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> v[i]; 
        }

        for (int i = 1; i <= N; i++)
        {
            if(!visit[i]) dfs(i);
        }
		
		cout << N - cnt << endl;

		cnt = 0;
        fill(visit, visit + (N + 1), false);
        fill(finish, finish + (N + 1), false);
    }
    return 0;
}