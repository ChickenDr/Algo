#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[101][101], inf = 90000001, n, m;

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = (i == j) ? 0 : inf;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        graph[from][to] = min(graph[from][to], w);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            } 
        }
    }
        
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (graph[i][j] == inf) cout << 0 << " ";
            else cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}