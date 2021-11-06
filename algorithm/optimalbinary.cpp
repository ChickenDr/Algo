#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
	friend class OBS;

public:
	TreeNode() {};
	TreeNode(int thePair) {
		key = thePair;
		left = 0;
		right = 0;
	}

private:
	int key;
	TreeNode *left;
	TreeNode *right;
};

// 트리의 루트 노드
TreeNode * node_pointer;

class OBS {
public:
	TreeNode tree(int i, int j);
	void optsearchtree(int n);
	int minimum(int m, int cost);
private:
	const vector<float> p;
	float& minavg;
	vector<vector<int>> R;
};

TreeNode OBS::tree(int i, int j) {
	int k;
	TreeNode * p = node_pointer;
	k = R[i][j];
	if (k == 0)
		return NULL;
	else {
		p = new nodetype;
		p->key = key[k];
		p->left = tree(i, k - 1);
		p->right = tree(k + 1, j);
		return p;
	}
}

int OBS::minimum(int m, int cost) {
	if (m < cost) {
		return m;
	}
	else return cost;
}

void OBS::optsearchtree(int n) {
	int i, j, k, diagonal;
	vector<vector<float>> A(n + 1, vector<float>(n, 0));
	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0; A[i][i] = p[i]; R[i][i] = i; R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0; R[n + 1][n] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			for (int k = i; k <= j - 1; k++) {
				A[i][j] = minimum(A[i][j], A[i][k - 1] + A[k + 1][j]) + p[i][j];
				R[i][j] = a value of k that gave the minimum;
			}
		}
	minavg = A[1][n];
}

int main() {

	return 0;
}