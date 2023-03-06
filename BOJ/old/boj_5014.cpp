#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;
int F, S, G, U, D, minlevel = 100000000, level = 0, m[2000001];
bool visit[2000001], check;
queue<int> qu;

void dfs(int x){
    qu.push(x);
    visit[x] = true;
    m[x] = level;

    while(!qu.empty()){
        int quSize = qu.size();
        for (int i = 0; i < quSize; i++)
        {
            int curr = qu.front();
            qu.pop();

            if (curr == G)
            {
                minlevel = min(minlevel, level);
                check = true;
            }
            
            if(curr - D > 0){
                if(visit[curr - D]){
                    m[curr - D] = min(m[curr - D], level);
                }
                else{
                    visit[curr - D] = true;
                    qu.push(curr - D);
                }
            }

            if(curr + U <= F){
                if(visit[curr + U]){
                    m[curr + U] = min(m[curr - U], level);
                }
                else{
                    qu.push(curr + U);
                    visit[curr + U] = true;
                }
            }
        }
        level++;
    }
}
int main(){
    cin >> F >> S >> G >> U >> D;
    dfs(S);

    if(check){
        cout << minlevel;
    }
    else{
        cout << "use the stairs";
    }

    return 0;
}