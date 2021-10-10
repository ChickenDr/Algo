#include <iostream>

using namespace std;

int arry[1001][101];

int Euclidean(int n, int m)
{
	if (n == 0) return m;
	int c;
	while (m)
	{
		c = n % m;
		n = m;
		m = c;
	}
	return n;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		long long reasult = 0;
		int loop;
		scanf("%d", &loop);
		arry[i][0] = loop;
		for (int x = 1; x <= loop; x++)
		{
			scanf("%d", &arry[i][x]);
		}

		for (int x = 1; x <= arry[i][0]; x++)
		{
			for (int j = 1; j <= arry[i][0]; j++)
			{
				if (x == j) continue;
				reasult += Euclidean(arry[i][x], arry[i][j]);
			}
		}
		cout << reasult << endl;
	}
	return 0;
}