#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N, total_cnt = 0;
bool map[20][20];

bool column(int x){
    for (int i = 0; i < N; i++)
    {
        if(map[x][i]) return false;
    }
    return true;
}

bool row(int x){
    for (int i = 0; i < N; i++)
    {
        if(map[i][x]) return false;
    }
    return true;
}

bool check(int y, int x){
    int j = y;
    int i = x;
    while(j >= 0 && i >= 0) {
        if(map[j][i]) return false;
        i--;
        j--;
    }
    
    j = y;
    i = x;
    while(j >= 0 && i < N) {
        if(map[j][i]) return false;
        j--;
        i++;
    }

    return true;
}

void backtrack(int x){
    if(x == N) {
        total_cnt++;
        return;
    }

    for (int i = 0; i < N; i++){
        if(!column(x) || !row(i)) continue;
        if(!check(x, i)) continue;

        map[x][i] = true; 
        backtrack(x + 1);
        map[x][i] = false;
    }
}

int main(){
    cin >> N;

    backtrack(0);
    cout << total_cnt;
    return 0;
}