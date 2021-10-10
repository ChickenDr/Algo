#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
	int n, m;
	vector<int> vcolor;
	vector<vector<bool>> W;
public:
	Graph(int tmpn, int tmpm, vector<vector<bool>> tmpW) {
		n = tmpn;
		m = tmpm;
		W = tmpW;
		vector<int> tmpv(n+1, 0);
		vcolor = tmpv;
	}
	void m_coloring(int i);
	bool promising(int i);
};

void Graph::m_coloring(int i) {
	int color;
	if (promising(i))
		if (i == n) {
			for (int x = 1; x < n+1; x++) {
				cout << "v" << "=" << vcolor[x] << " ";
			}
			cout << endl;
		}
		else
			for (color = 1; color <= m; color++) {
				vcolor[i + 1] = color;
				m_coloring(i + 1);
			}
}

bool Graph::promising(int i) {
	int j; bool swt;
	swt = true;
	j = 1;
	while (j<i && swt) {
		if (W[i][j] && vcolor[i] == vcolor[j]) swt = false;
		j++;
	}
	return swt;
}

int main() {
	cout << "교제의 데이터를 실행 합니다." << endl;
	Graph graph2(4, 3, { { false, false, false, false, false },
		{ false, false, true, false, true },
		{ false, true, false, true, false },
		{ false, true, true, false, true },
		{ false, true, false, true, false } });
	graph2.m_coloring(0);

	cout << "자작 데이터를 실행합니다." << endl;
	Graph graph(4, 3, { { false, false, false, false, false },
						{ false, false, true, false, true },
						{ false, true, false, true, true },
						{ false, false, true, false, true },
						{ false, true, true, true, false } });
	graph.m_coloring(0);
	return 0;
}