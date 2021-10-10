#include <iostream>
#include <string>

using namespace std;
int main()
{
	string a;
	cin >> a;

	int len = a.length();
	int left = len % 3;
	if (left == 1)
	{
		cout << a[0];
	}
	else if (left == 2)
	{
		int temp = ((int)a[0] - 48) * 2 + a[1] - 48;
		cout << temp;
	}
	for (int i = left; i < len; i += 3)
	{
		int temp = ((int)a[i] - 48) * 4 + (a[i + 1] - 48) * 2 + (a[i + 2] - 48);
		cout << temp;
	}
	cout << endl;
}