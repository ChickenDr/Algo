#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int R, C, MAX = -1;
bool visit[21][21], a_visit[25];
char a[21][21];

void back(int x, int y, int cnt){
    visit[x][y] = true;
    a_visit[a[x][y] - 'A'] = true;
    MAX = max(MAX, cnt);

    if(y + 1 <= C && !visit[x][y + 1] && !a_visit[a[x][y + 1] - 'A']) back(x, y + 1, cnt + 1);
    if(y - 1 >= 1 && !visit[x][y - 1] && !a_visit[a[x][y - 1] - 'A']) back(x, y - 1, cnt + 1);
    if(x + 1 <= R && !visit[x + 1][y] && !a_visit[a[x + 1][y] - 'A']) back(x + 1, y, cnt + 1);
    if(x - 1 >= 1 && !visit[x - 1][y] && !a_visit[a[x - 1][y] - 'A']) back(x - 1, y, cnt + 1);

    visit[x][y] = false;
    a_visit[a[x][y]-'A'] = false;
    return;
}

int main(){
    cin >> R >> C;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> a[i][j];
        }
    }

    back(1, 1, 1);
    cout << MAX;
    return 0;
}