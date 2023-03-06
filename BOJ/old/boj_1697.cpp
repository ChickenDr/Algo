#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, K, resualt = 0;
bool visited[100001];

int dfs(int x){
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int tmp = q.size();
        for (int i = 0; i < tmp; i++)
        {
            int curr = q.front();
            q.pop();

            if(curr == K) return resualt;

            if(curr - 1 >= 0 && !visited[curr - 1]){
                q.push(curr - 1);
                visited[curr - 1] = true;
            }

            if(curr + 1 <= 100000 && !visited[curr + 1]){
                q.push(curr + 1);
                visited[curr + 1] = true;
            }

            if(curr * 2 <= 100000 && !visited[curr * 2]){
                q.push(curr * 2);
                visited[curr * 2] = true;
            }   
        }
        resualt++;
    }
}

int main(){
    memset(visited, false, sizeof(visited));
    cin >> N >> K;

    cout << dfs(N) << endl;

    return 0;
}