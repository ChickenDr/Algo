#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a;
	cin >> a;
	vector<int> num(a);
	vector<int> tmp(a);

	for (int i = 0; i < a; i++) {
		cin >> num[i];
	}

	tmp[0] = num[0];
	int MAX = tmp[0];

	for (int i = 1; i < a; i++) {
		tmp[i] = max(num[i], tmp[i - 1] + num[i]);
		MAX = max(MAX, tmp[i]);
	}

	cout << MAX;
	return 0;
}