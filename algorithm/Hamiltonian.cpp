#include <iostream>
#include <vector>

using namespace std;

class Hamiltonian {
private:
	int n;
	vector<int> vindex;
	vector<vector<bool>> W;
public:
	Hamiltonian(int tmpn, vector<vector<bool>> tmpW) {
		n = tmpn;
		vector<int> tmp(n+1, 1);
		vindex = tmp;
		W = tmpW;
	}

	void hamiltonian(int i);
	bool promising(int i);
};

void Hamiltonian::hamiltonian(int i) {
	int j;

	if (promising(i))
		if (i == n - 1) {
			for (int x = 1; x < n + 1; x++) {
				cout << "v" << "=" << vindex[x] << " ";
			}
			cout << endl;
		}
		else {
			for (j = 2; j <= n; j++) { // Try all vertices as
				vindex[i + 1] = j; // next one.
				hamiltonian(i + 1);
			}
		}
}

bool Hamiltonian::promising(int i) {
	int j; bool swt;
	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
		swt = false;
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
		swt = false;
	else {
		swt = true;
		j = 1;
		while (j<i && swt) {
			if (vindex[i] == vindex[j]) swt = false;
			j++;
		}
	}
	return swt;
}

int main() {
	Hamiltonian hamiltonian(5, { { false,false,false,false,false,false },
								 { false,false, true, false, true, false },
								 { false, true,false, true,false,true },
								 { false, false, true,false, true,false },
								 { false,true,false, true,false, false},
								 { false,true,true, false,false, false} });
	hamiltonian.hamiltonian(0);
	return 0;
}