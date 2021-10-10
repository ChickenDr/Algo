#include <iostream>

using namespace std;
int n, maxPower = 0;

int main()
{
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		maxPower += tmp;
	}
	
	cout << maxPower - (n - 1);
	return 0;
}