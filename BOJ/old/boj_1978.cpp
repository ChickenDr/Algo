#include <iostream>

using namespace std;
int n;
int arry[10001] = { 1, 1, };

int main()
{
	cin >> n;
	for (int x = 2; x * x <= 10000; ++x)
	{
		for (int j = x * x; j <= 10000; j += x)
		{
			arry[j] = 1;
		}
	}

	int tmp, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (arry[tmp] != 1)
		{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}