#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, level = 0, cnt = 0, v[301][301], tv[301][301];
bool visit[301][301];

void dfs(int x, int y){
	visit[x][y] = true;
	
    if(v[x][y - 1] > 0 && y > 0 && !visit[x][y - 1]) dfs(x, y - 1);
    if(v[x][y + 1] > 0 && y < M && !visit[x][y + 1]) dfs(x, y + 1);
    if(v[x - 1][y] > 0 && x > 0 && !visit[x - 1][y]) dfs(x - 1, y);
    if(v[x + 1][y] > 0 && x < N && !visit[x + 1][y]) dfs(x + 1, y);
}

void melt(){
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			    tv[i][j] = v[i][j];
		}
	}

    for (int x = 1; x < N; x++) {
		for (int y = 1; y < M; y++) {
            if(tv[x][y] > 0){

                int melt_c = 0;
	            if(tv[x][y - 1] == 0) melt_c++;
                if(tv[x][y + 1] == 0) melt_c++;
                if(tv[x - 1][y] == 0) melt_c++;
                if(tv[x + 1][y] == 0) melt_c++;

	            v[x][y] -= melt_c;
	            if(v[x][y] < 0) v[x][y] = 0;   
            }
        }
    }
}

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
		for (int j = 0; j < M; j++)
		{
			cin >> v[i][j];
    	}
	}
	
	while(1)
	{
        memset(visit, false, sizeof(visit));
        for (int x = 1; x < N; x++) {
			for (int y = 1; y < M; y++) {
				if (v[x][y] != 0 && !visit[x][y]) {
					cnt++;
					if (cnt == 2) {
						cout << level;
						return 0;
					}   
					dfs(x, y);
				}
			}
		}

		if (cnt == 0) {
			cout << 0;
			break;
		}
		
        melt();
        cnt = 0;
		level++;
	}

    return 0;
} 