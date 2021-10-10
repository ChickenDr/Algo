#include <iostream>
#include <string>
using namespace std;

int arry[101];
string a;
int main()
{
	int N;
	cin >> N;

	for (int x = 0; x < N; x++)
	{
		cin >> a;

		if (a[a.length() - 1] % 2 == 0) cout << "even" << endl;
		else cout << "odd" << endl;
	}

	return 0;
}