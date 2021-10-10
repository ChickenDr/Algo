#include <iostream>
#include <vector>
#include <utility>

#define MAX 100000

using namespace std;

class Dijkstra {
public:
	Dijkstra(){}
	Dijkstra(vector<vector<int>> tmpW) {
		W = tmpW;
	}
	void dijkstra(int n);
	void print();
private:
	vector<vector<int>> W;
	vector<pair<int, pair<int, int>>> F;
};

void Dijkstra::print() {
	cout << "경로 :" << " 가중치" << endl;
	for (int i = 0; i < F.size(); i++) {
		cout << F[i].second.first << " -> " << F[i].second.second << " : " << F[i].first << endl;
	}
}

void Dijkstra::dijkstra(int n) {
	int i, vnear;

	vector<int> touch(n+2, 0);
	vector<int> length(n+2, 0);
	pair<int, pair<int, int>> e;
	for (i = 2; i <= n; i++) { 
		touch[i] = 1;
		length[i] = W[1][i];
	}

	for (int tmp = 1; tmp <= (n - 1); tmp++) { 
		int min = MAX;
		for (i = 2; i <= n; i++) { 
			if (0 <= length[i] && length[i] <= min) {
				min = length[i];
				vnear = i;
			}
		}

		e.first = W[touch[vnear]][vnear]; e.second.first = touch[vnear]; e.second.second = vnear;
		F.push_back(e);

		for (i = 2; i <= n; i++)
			if (length[vnear] + W[vnear][i] < length[i]) {
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear;
			}
		length[vnear] = -1;
	}
}



int main() {
	cout << "교제의 데이터를 테스트 합니다." << endl;

	Dijkstra dij({ { 0, 0, 0, 0, 0, 0},
				  {0, MAX, 7, 4, 6, 1},
				  {0, MAX, MAX, MAX, MAX, MAX},
				  {0, MAX, 2, MAX, 5, MAX},
				  {0, MAX, 3, MAX, MAX, MAX},
				  {0, MAX, MAX, MAX, 1, MAX} });
	
	dij.dijkstra(5);
	dij.print();

	cout << "임의의 데이터를 입력해 주세요." << endl;
	int n;
	cout << "정점의 개수를 입력해 주세요." << endl;
	cin >> n;
	cout << "그래프를 입력해 주세요. (INF = 10000)" << endl;
	vector<vector<int>> tmp(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int x = 1; x <= n; x++) {
			cin >> tmp[i][x];
		}
	}
	Dijkstra dij2(tmp);
	dij2.dijkstra(n);
	dij2.print();

	return 0;
}