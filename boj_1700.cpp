#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, K, cnt = 0, plug = 0;
	vector<int> pluged(101);
	vector<int> pin;
	vector<queue<int>> elc(101);

	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		int tmp;
		cin >> tmp;

		if (plug < N) {
			if (pluged[tmp] == 1) continue;
			else {
				pluged[tmp] = 1;
				plug++;
			}
		}
		else {
			pin.push_back(tmp);
			elc[tmp].push(i);
		}
	}
	
	for (int x = 0; x < pin.size(); x++) {
		if (plug < N && pluged[pin[x]] != 1) {
			pluged[pin[x]] = 1;
			plug++;
		}

		else if (pluged[pin[x]] == 1) {
			elc[pin[x]].pop();
			continue;
		}

		else {
			int max = -1, index;
			for (int j = 1; j <= K; j++) {
 				if (pluged[j] == 1) {
					if (elc[j].empty()) {
						pluged[j] = 0;
						pluged[pin[x]] = 1;
						elc[pin[x]].pop();
						cnt++;
						max = -1;
						break;
					}
					else {
						if (elc[j].front() > max) {
							max = elc[j].front();
							index = j;
						}
					}
				}
			}

			if (max > 0) {
				pluged[index] = 0;
				pluged[pin[x]] = 1;
				elc[pin[x]].pop();
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}