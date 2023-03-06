#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, level = 0, cnt = 0;
vector<vector<int>> v(100, vector<int>(100));

int dfs(int x, int y){
    v[x][y] = -1;
	cnt += 1;

    if(v[x][y - 1] == 1 && y > 0) dfs(x, y - 1);
    if(v[x][y + 1] == 1 && y < N) dfs(x, y + 1);
    if(v[x - 1][y] == 1 && x > 0) dfs(x - 1, y);
    if(v[x + 1][y] == 1 && x < N) dfs(x + 1, y);

    return 0;
}

int main(){
    cin >> N;
	vector<int> resualt;
	
    for (int i = 1; i <= N; i++)
    {
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &v[i][j]);
    	}
	}
	
	for (int k = 1; k <= N; k++)
    {
		for(int j = 1; j <= N; j++){
			if(v[k][j] == 1){
	        	dfs(k, j);
				resualt.push_back(cnt);
				cnt = 0;
				level++;
        	}
		}
    }
	
	sort(resualt.begin(), resualt.end());
	
	cout << level << endl;
	for(int i = 0; i < resualt.size(); i++){
		cout << resualt[i] << endl;
	}
    return 0;
} 