#include <iostream>

using namespace std;

int n, m;

int gcd(int n, int m)
{
	if (m == 0)
	{
		return n;
	}
	return gcd(m, n%m);
}

int gcm(int n, int m)
{
	return m * n/ gcd(m, n);
}

int main()
{
	cin >> n >> m;
	cout << gcd(n, m) << endl;
	cout << gcm(n, m);
	return 0;
}