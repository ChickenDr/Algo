#include <iostream>

using namespace std;
int n, m, enterCar = 0, exitCar = 0, tmp = 0, maxCar = 0;

int main()
{
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> enterCar >> exitCar;
		m += enterCar;
		m -= exitCar;
		if (m < 0)
		{
			tmp = 1;
		}
		if (m > maxCar)
		{
			maxCar = m;
		}
	}
	if (tmp == 1)
	{
		cout << '0';
	}
	else
	{
		cout << maxCar;
	}
	return 0;
}