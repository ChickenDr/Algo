#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;

class ChainedMatrix{
private:
	vector<int> d;
	vector<vector<int>> P;

public:
	ChainedMatrix() {};
	ChainedMatrix(vector<int> tmpd) {
		d = tmpd;
		vector<vector<int>> tmpP(d.size(), vector<int>(d.size(), 0));
		P = tmpP;
	}
	int minmult();
	int minimum(int m, int cost);
	void print(int i, int j);
	void order(int i, int j);
};

void ChainedMatrix::print(int i, int j) {
	cout << "데이터: " << endl;
	for (int n = 0; n < d.size(); n++) {
		cout << d[n] << " ";
	}
	cout << endl;
	cout << "[" << i << "]" << "[" << j << "]" << "의 최적의 분해를 찾습니다." << endl;
	order(i - 1, j - 1);
	cout << endl;
}

void ChainedMatrix::order(int i, int j) {
	if (i == j) cout << "A" << i + 1;
	else {
		int k = P[i][j];
		cout << "(";
		order(i, k);
		order(k + 1, j);
		cout << ")";
	}
}

int ChainedMatrix::minimum(int m, int cost) {
	if (m < cost) {
		return m;
	}
	else return cost;
}

int ChainedMatrix::minmult() {
	int j;
	int n = d.size();
	vector<vector<int>> M(n, vector<int>(n, MAX));

	for (int diagonal = 1; diagonal <= n - 1; diagonal++)
		for (int i = 1; i <= n - diagonal; i++) {
			j = i + diagonal - 1;
			if (i == j) {
				M[i][j] = 0;
				continue;
			}
			for (int k = i; k <= j - 1; k++) {
				M[i][j] = minimum(M[i][j], M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]);
				P[i][j] = k;
			}
		}
	return M[1][n - 1];
}

int main() {
	cout << "----------교제의 데이터---------" << endl;
	ChainedMatrix chain({5, 2, 3, 4, 6, 7, 8});
	chain.minmult();
	chain.print(1, 6);

	cout << "----------임의의 데이터---------" << endl;
	cout << "데이터의 개수를 입력해 주세요" << endl;
	int n, a;
	cin >> n;
	vector<int> tmp(n, 0);
	for (int i = 0; i < n; i++) {	
		cin >> tmp[i];
	}
	ChainedMatrix chain2(tmp);
	chain2.minmult();
	chain2.print(1, 6);

	return 0;
}