#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, x, y, resualt_x, resualt_y, resualt[101];
vector<int> v[101];
queue<int> qu;

int bfs(){
    qu.push(resualt_x);

    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();

        if(curr == resualt_y)
        {
            return resualt[resualt_y];
        }

        for (int i = 0; i < v[curr].size(); i++)
        {
            int next = v[curr][i];

            if(resualt[next] == 0){
                qu.push(next);
                resualt[next] = resualt[curr] + 1;
            }
        }

    }

    return -1;
}


int main(){
    cin >> N;
    cin >> resualt_x >> resualt_y;
    
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    cout << bfs();
    return 0;
}