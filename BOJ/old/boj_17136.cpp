#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int map[20][20], p_cnt[6], min_paper = 100000;

bool can_cover(int x, int y, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(!map[x + i][y + j]) return false;
        }
    }
    return true;
}

void visited(int x, int y, int size, bool check ){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            map[x + i][y + j] = check;
        }
    }
}

void backtrack(int x, int y, int paper){
    bool flag = false;
    for (int i = x; i <= 10; i++){
        for (int j = 0; j <= 10; j++)
        {
            if (i == 10 && j == 10) {
            min_paper = min(min_paper, paper);
            return;
            }

            if (map[i][j] == 1){
                x = i;
                y = j;
                flag = true;
                break;
            }
            
        }
        if (flag) break;
    }

    if(min_paper <= paper) return;
    
    for (int i = 5; i > 0; i--)
    {
        if(x + i > 10 || y  + i > 10 || p_cnt[i] == 5) continue;
        if(can_cover(x, y, i)){
            visited(x, y, i, 0);
            ++p_cnt[i];

            backtrack(x, y, paper + 1);

            visited(x, y, i, 1);
            --p_cnt[i];
        }
    }
}

int main(){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> map[i][j];
        }
    }
    
    backtrack(0, 0, 0);
    if(min_paper == 100000) min_paper = -1;
    cout << min_paper;
    return 0;
}