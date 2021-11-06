#include <iostream>
#include <vector>

using namespace std;

class Subset {
private:
	vector<bool> include;
	int W;
	vector<int> w;
public:
	Subset(int n, vector<int>tmp) {
		vector<bool> tmpi(n, 0);
		include = tmpi;
		w = tmp;
	}
	Subset(int n){
		int a;
		for (int x = 0; x < n; x++) {
			cin >> a;
			w.push_back(a);
		}
	}
	void setW(int n) {
		W = n;
	}
	void sum_of_subsets(int i, int weight, int total);
	bool promising(int i, int weight, int total);
};

void Subset::sum_of_subsets(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (weight == W) {
			cout << W << "을 위한 최적의 합집합은" << endl;
			for (int x = 1; x < include.size(); x++) {
				if (include[x] == true) {
					cout << " true ";
				}
				else {
					cout << " flase ";
				}
			}
			cout << endl;
			for (int x = 0; x < include.size(); x++) {
				if (include[x] == true) {
					cout << w[x] << " + ";
				}
			}
			cout << " = " << W << endl;
		}
		else {
			include[i + 1] = true;
			sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = false;
			sum_of_subsets(i + 1, weight, total - w[i + 1]);
		}
	}
}
bool Subset::promising(int i, int weight, int total) {
	return (weight + total >= W)&&(weight == W || weight + w[i + 1] <= W);
}
int main() {
	cout << "교제의 데이터를 실행 합니다." << endl;
	Subset subset(5, { 0, 3, 4, 5, 6 });
	cout << "찾는 값 13" << endl;
	subset.setW(13);
	subset.sum_of_subsets(0, 0, 18);

	cout << "자작 데이터를 실행합니다. 주세요." << endl;
	Subset subset2(5, {0, 2, 4, 7, 9});
	cout << "찾는 값 20" << endl;
	subset2.setW(20);
	subset2.sum_of_subsets(0, 0, 22);
	return 0;
}