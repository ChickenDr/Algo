#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Kru {
private:
	vector<int> U;
	// vector
	// ----------------------------------------------
	// <(시작 마디), <(도착 마디), (가중치)>> 자료형
	// ----------------------------------------------
	vector<pair<int, pair<int, int>>> E;
	vector<pair<int, pair<int, int>>> F;
	int n;
public:
	Kru(int k) {
		n = k;
		vector<int> tmp(k, 0);
		for (int i = 0; i < k; i++) {
			tmp[i] = i;
		}
		U = tmp;
	}
	void merge(int p, int q);
	void kruskal();
	int find(int n);
	void add(int u, int v, int w);
	void print();
};

void Kru::add(int u, int v, int w) {
	E.push_back(make_pair(w,pair<int, int>(u, v)));
}

void Kru::merge(int p, int q) {
	if (p < q) {
		U[q] = p;
	}
	else {
		U[p] = q;
	}
}

int Kru::find(int n) {
	int j = n;
	while (U[j] != j) {
		j = U[j];
	}
	return j;
}

void Kru::print() {
	cout << "경로 :" << " 가중치" << endl;
	for (int i = 0; i < F.size(); i++) {
		cout << F[i].second.first + 1 << " <-> " << F[i].second.second + 1 << " : " << F[i].first << endl;
	}
}

void Kru::kruskal() {
	int i = 0, j = 0;
	int p, q;
	sort(E.begin(), E.end());
	while (F.size() != (n-1)) {
		p = find(E[i].second.first);
		q = find(E[j].second.second);
		if (p != q) {
			merge(p, q);
			F.push_back(E[i]);
		}
		i++;
		j++;
	}
}
int main() {
	cout << "교제 데이터의 결과를 출력 합니다." << endl;
	Kru kru(5);
	kru.add(0, 1, 1);
	kru.add(0, 2, 3);
	kru.add(1, 2, 3);
	kru.add(1, 3, 6);
	kru.add(2, 3, 4);
	kru.add(2, 4, 2);
	kru.add(3, 4, 5);
	kru.kruskal();
	kru.print();

	cout << "임의의 데이터를 테스트 합니다." <<endl;
	cout << "정점의 수, 이음선의 수 를 입력해 주세요" << endl;
	int n, m;
	int u, v, w;
	cin >> n >> m;

	Kru kru2(n);
	cout << "모서리  모서리  가중치 를 입력해 주세요" << endl;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		kru2.add(u-1, v-1, w);
	}
	kru2.kruskal();
	kru2.print();

	return 0;
}