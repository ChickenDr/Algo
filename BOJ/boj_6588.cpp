#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arry;
int cnt = 0;

int gold(int n)
{
	int tmp = n - arry[cnt];
	vector<int>::iterator p = std::find(arry.begin(), arry.end(), tmp);
	if (p != arry.end())
	{
		cnt = 0;
		cout << arry[cnt] << "+" << *p << endl;
	}
	else
	{
		cnt++;
		return gold(n);
	}
}

int main()
{
	int primeArry[1000001];

	for (int i = 2; i <= 1000001; i++)
	{
		primeArry[i] = true;
	}

	for (int x = 2; x * x <= 1000001; x++)
	{
		if (primeArry[x])
			for (int j = x * x; j <= 1000001; j += x)
			{
				primeArry[j] = false;
			}
	}

	for (int k = 2; k <= 1000001; k++)
	{
		if (primeArry[k])
			arry.push_back(k);
	}

	int N, tmp;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		gold(tmp);
	}
	return 0;
}