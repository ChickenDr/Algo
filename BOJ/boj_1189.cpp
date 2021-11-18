#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int R, C, K, x_m[4] = {1, -1, 0, 0}, y_m[4] = {0, 0, 1, -1};
int resualt_cnt = 0;
char v[10][10];
bool visit[10][10];

bool promising(int x, int y){
    if(x > R || x <= 0 || y > C || y <= 0 || visit[x][y]) return false;
    if(v[x][y] == 'T') return false;
    return true; 
}

void backtracking(int x, int y, int cnt){
    if(y == C && x == 1 && cnt == K){
        resualt_cnt++;
        return;
    }

    visit[x][y] = true;
    for (int i = 0; i < 4; i++)
    {        
        if (promising(x + x_m[i], y + y_m[i]))
        {
            backtracking(x + x_m[i], y + y_m[i], cnt + 1);
        }
    }
    visit[x][y] = false;
}

int main(){
    cin >> R >> C >> K;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> v[i][j];
        }
    }
    
    backtracking(R, 1, 1);
    cout << resualt_cnt;
    return 0;
}