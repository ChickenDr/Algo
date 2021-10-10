#include <iostream>

using namespace std;
int P, L, V, cnt = 1;

int main()
{
	while (1)
	{
		cin >> L >> P >> V;
		if (L == 0 || P == 0 || V == 0)
		{
			break;
		}

		int cant = P - L, cmp = 0;
		while (P <= V) {
			V -= (L + cant);
			cmp += L;
		}
		if (L >= V) cmp += V;
		else if (L < V) cmp += L;
		
		cout << "Case " << cnt++ << ": " << cmp << endl;
	}
	return 0;
}