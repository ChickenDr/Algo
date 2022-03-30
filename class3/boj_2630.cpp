#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int N, map[130][130], blue = 0, white = 0;

bool same(int N, int x, int y)
{
    for (int i = x; i < x + N; i++)
    {
        for (int j = y; j < y + N; j++)
        {
            if(map[i][j] != map[x][y]) 
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int N, int x, int y)
{
    if(same(N, x, y))
    {
        if(map[x][y] == 1)
        {
            blue++;
        }
        else
        {
            white++;
        }
        return;
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                solve(N / 2, x + (i * (N / 2)), y + (j * (N / 2)));
            }
        }
        
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    solve(N, 0, 0);

    cout << white << " " << blue << endl;
    return 0;
}