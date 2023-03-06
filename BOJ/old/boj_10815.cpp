#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, tmp;
int arry[20000001] = { 0, };

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		arry[tmp + 10000000] = 1;
	}

	scanf("%d", &m);
	for (int x = 0; x < m; x++)
	{
		scanf("%d", &tmp);
		if (arry[tmp + 10000000] == 1)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
	}
	return 0;
}