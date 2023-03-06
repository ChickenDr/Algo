#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> num(9);

	for (int i = 0; i < 9; i++) {
		cin >> num[i];
	}

	int Max = 0;
	for (int i = 0; i < 9; i++) {
		Max += num[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int x = 0; x < 9; x++) {
			if (i == x) continue;
			if ((Max - (num[i] + num[x])) == 100) {
				num[i] = -1;
				num[x] = -1;
				sort(num.begin(), num.end());
				for (int i = 2; i < 9; i++) {
					cout << num[i] << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}
