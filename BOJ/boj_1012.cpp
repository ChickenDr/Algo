#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v(3000, vector<int>(3000));
int x_m, y_m, K, cnt = 0;

int dfs(int x, int y){
    v[x][y] = -1;

    if(v[x][y - 1] == 1 && y > 0) dfs(x, y - 1);
    if(v[x][y + 1] == 1 && y < y_m) dfs(x, y + 1);
    if(v[x - 1][y] == 1 && x > 0) dfs(x - 1, y);
    if(v[x + 1][y] == 1 && x < x_m) dfs(x + 1, y);
    
    return 0;
}

int main(){
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int x, y;
        
        cin >> x_m >> y_m >> K;
        vector<pair<int, int>> tmp;
        
        for (int j  = 0; j < K; j++)
        {
			cin >> x >> y;
            v[x + 1][y + 1] = 1;
            tmp.push_back(make_pair(x + 1, y + 1));
        }
        
        for (int k = 0; k < K; k++)
        {
            if(v[tmp[k].first][tmp[k].second] == 1){
	            dfs(tmp[k].first, tmp[k].second);
                cnt++;
            }
        }
        cout << cnt << endl;
		cnt = 0;
    }
    return 0;
}