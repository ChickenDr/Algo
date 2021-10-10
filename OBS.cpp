#include <iostream>
#include <vector>
#define MAX 10000

using namespace std;

class OBS {
private:
	vector<float> p;
	float minavg;
	vector<vector<int>> R;
public:
	OBS() {};
	OBS(vector<float> tmp){
		p = tmp;
		vector<vector<int>> tmpR(p.size()+1, vector<int>(p.size()+1, 0));
		R = tmpR;
	}
	void optsearchtree();
	float min(float n, float m);
	float sum(int i, int j);
};

float OBS::sum(int i, int j) {
	float sum = 0.0;
	for (i; i <= j; i++) {
		sum += p[i];
	}
	return sum;
}

float OBS::min(float n, float m) {
	if (m < n) {
		return m;
	}
	else return n;
}

void OBS::optsearchtree() {
	int i, j, diagonal;
	float cost;
	int n = p.size() - 1;
	vector<vector<float>> A(n + 2, vector<float>(n+1, 0));

	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0; 
		A[i][i] = p[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0; R[n + 1][n] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			cost = A[i][i - 1] + A[i + 1][j] + sum(i, j);
			for (int k = i; k <= j; k++) {
				if (cost >= A[i][k - 1] + A[k + 1][j] + sum(i, j)) {
					cost = A[i][k - 1] + A[k + 1][j] + sum(i, j);
					R[i][j] = k;
				}
			}
			A[i][j] = cost;
		}
	minavg = A[1][n];

	cout << "배열 A의 출력 " << endl;
	for (int x = 1; x <= n; x++) {
		for (int a = x; a <= n; a++) {
			cout << A[x][a] << " ";
		}
		cout << endl;
	}

	cout << "배열 R의 출력 " << endl;
	for (int x = 1; x <= n; x++) {
		for (int a = x; a <= n; a++) {
			cout << R[x][a] << " ";
		}
		cout << endl;
	}
	cout << "가장 작은 avg" << endl;
	cout << minavg << endl;
}

int main() {
	OBS obs({NULL, 3.0 / 8.0, 3.0 / 8.0, 1.0 / 8.0, 1.0 / 8.0 });
	obs.optsearchtree();

	cout << "자작 데이터의 개수를 입력해 주세요" << endl;
	int n;
	cin >> n;
	// 사용한 자작 데이터
	// 0.25, 0.25 0.375 0.125
	vector<float> tmp(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> tmp[i];
	}
	OBS obs2(tmp);
	obs2.optsearchtree();

	return 0;
}