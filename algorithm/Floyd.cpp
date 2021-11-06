#include <iostream>
#include <vector>
#include <limits>
#define inf 10000

using namespace std;

class Floyd {
private:
	vector<vector<int>> D, W, P;
	int n;
public:
	Floyd() {  };
	Floyd(vector<vector<int>>w) {
		W = w;
		D = w;
		n = size(W);
		vector<vector<int>> tmp(size(W), vector<int>(size(W), 0));
		P = tmp;
	}

	void floyd2();
	void print(int q, int r);
	int minimum(int d, int w);
	void path(int q, int r);
};

int Floyd::minimum(int d, int w) {
	if (d < w) return d;
	else w;
}

vector<vector<int>> inputpath(int n) {
	cout << "����ġ �׷����� �����ּ��� (inf�� 10000)" << endl;
	vector<vector<int>> tmp (n, vector<int>(n, 0));
	for (int x = 0; x < n; x++) {
		for (int i = 0; i < n; i++) {
			cin >> tmp[x][i];
		}
	}
	return tmp;
}

void Floyd::floyd2() {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k + 1;
					D[i][j] = D[i][k] + D[k][j];
				}
}

void Floyd::print(int q, int r) {
	cout << q << "����" << r << "������ �ִ� ��δ�" << endl;
	cout << "v" << q << "->";
	path(q - 1, r - 1);
	cout << "v" << r << endl;
}

void Floyd::path(int q, int r) {
	if (P[q][r] != 0) {
		path(q, P[q][r] - 1);
		cout << "v" << P[q][r] << "->";
		path(P[q][r] - 1, r);
	}
}

int main() {
	Floyd sortpass({ {0, 1, inf, 1, 5}, {9, 0, 3, 2, inf}, {inf, inf, 0, 4, inf}, {inf, inf, 2, 0, 3}, {3, inf, inf, inf, 0} });
	cout << "-------------���� ������-------------" << endl;
	sortpass.floyd2(); 
	sortpass.print(5, 3);
	
	int n, x, y;
	cout << "------------���� �Է� ������ ---------" << endl;
	cout << "���� �������� ���� ������ �Է��� �ּ���.:";
	cin >> n;
	Floyd sortpass2(inputpath(n));
	sortpass2.floyd2();
	cout << "�˰���� �ִ� ��θ� �Է��� �ּ���." << endl;
	cin >> x >> y;
	sortpass2.print(x, y); 

	return 0;
}