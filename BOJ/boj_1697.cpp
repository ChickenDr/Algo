#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, K, resualt = 1000000;
bool visited[100001];

void dfs(int x, int dst){
    queue<pair<int, int> > q;
    q.push(make_pair(x, dst));
    visited[x] = true;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();

        if(curr.first == K){
            resualt = min(resualt, curr.second);
            continue;
        }

        if(x - 1 >= 0 && !visited[x - 1]){
            q.push(make_pair(curr.first - 1, curr.second + 1));
            visited[curr.first] = true;
        }
        if(!visited[x + 1]){
            q.push(make_pair(curr.first + 1, curr.second + 1));
            visited[curr.first] = true;
        }
        if(!visited[x * 2]){
            q.push(make_pair(curr.first * 2, curr.second + 1));
            visited[curr.first] = true;
        }
    }
}

int main(){
    cin >> N >> K;

    dfs(N, 0);
    cout << resualt << endl;

    return 0;
}