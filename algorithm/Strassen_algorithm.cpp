#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
	vector<vector<int>> mA, mB;
public:
	Matrix() {};

	Matrix(vector<vector<int>> A, vector<vector<int>> B) {
		mA = A;
		mB = B;
		cout << "행렬 A가 입력 되었습니다." << endl;
		check(A);

		cout << "행렬 B가 입력 되었습니다." << endl;
		check(B);
	}

	vector<vector<int>> subMatrix(vector<vector<int>> A, vector<vector<int>> B);
	vector<vector<int>> sumMatrix(vector<vector<int>>A, vector<vector<int>> B);
	vector<vector<int>> mulMatrix(vector<vector<int>> A, vector<vector<int>> B);
	vector<vector<int>> MatrixSum(vector<vector<int>> c11, vector<vector<int>> c12, vector<vector<int>> c21, vector < vector<int>> c22);
	void sliceMatrix(int n, vector<vector<int>> &m11, vector<vector<int>> &m12, vector<vector<int>> &m21, vector<vector<int>> &m22, vector<vector<int>> original);
	vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B);

	void check(vector<vector<int>> C);
};

void Matrix::check(vector<vector<int>> C) {
	for (int x = 0; x < C.size(); x++) {
		for (int i = 0; i < C.size(); i++) {
			cout.flags(ios::left);
			cout.width(3);
			cout << C[x][i] << " | ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<int>> Matrix::MatrixSum(vector<vector<int>> c11, vector<vector<int>> c12, vector<vector<int>> c21, vector < vector<int>> c22) {
	int n = c11.size();
	vector<vector<int>> tmpMatrix(n*2, vector<int>(n*2 , 0));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmpMatrix[i][j] = c11[i][j];
			tmpMatrix[i][j + n] = c12[i][j];
			tmpMatrix[i + n][j] = c21[i][j];
			tmpMatrix[i + n][j + n] = c22[i][j];
		}
	}

	return tmpMatrix;
}

vector<vector<int>> Matrix::sumMatrix(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> tmpMatrix(A.size(), vector<int>(A.size(), 0));

	for (int i = 0; i < A.size(); i++) {
		for (int x = 0; x < A.size(); x++) {
			tmpMatrix[i][x] = A[i][x] + B[i][x];
		}
	}
	return tmpMatrix;
}

vector<vector<int>> Matrix::subMatrix(vector<vector<int>> A, vector<vector<int>> B) {
	vector<vector<int>> tmpMatrix(A.size(), vector<int>(A.size(), 0));

	for (int i = 0; i < A.size(); i++) {
		for (int x = 0; x < A.size(); x++) {
			tmpMatrix[i][x] = A[i][x] - B[i][x];
		}
	}
	return tmpMatrix;
}

vector<vector<int>> Matrix::mulMatrix(vector<vector<int>> A, vector<vector<int>> B) {
	int n = A.size();
	vector<vector<int>> tmpMatrix(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmpMatrix[i][j] += A[i][k] * B[k][j];
			}
		}

	}
	return tmpMatrix;
}

void Matrix::sliceMatrix(int n, vector<vector<int>> &m11, vector<vector<int>> &m12, vector<vector<int>> &m21, vector<vector<int>> &m22, vector<vector<int>> original) {
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < n; x++) {
			m11[i][x] = original[i][x];
			m12[i][x] = original[i][x + n];
			m21[i][x] = original[i + n][x];
			m22[i][x] = original[i + n][x + n];
		}
	}
}

vector<vector<int>> Matrix::strassen(vector<vector<int>> A, vector<vector<int>> B) {
	if (A.size() <= 1) {
		return mulMatrix(A, B);
	}
	else {
		int subn = (A.size()) / 2;

		vector<vector<int>> a11(subn, vector<int>(subn, 0));
		vector<vector<int>> a12(subn, vector<int>(subn, 0));
		vector<vector<int>> a21(subn, vector<int>(subn, 0));
		vector<vector<int>> a22(subn, vector<int>(subn, 0));
		sliceMatrix(subn, a11, a12, a21, a22, A);

		vector<vector<int>> b11(subn, vector<int>(subn, 0));
		vector<vector<int>> b12(subn, vector<int>(subn, 0));
		vector<vector<int>> b21(subn, vector<int>(subn, 0));
		vector<vector<int>> b22(subn, vector<int>(subn, 0));
		sliceMatrix(subn, b11, b12, b21, b22, B);

		// 계산 결과 임시 저장 배열
		vector<vector<int>> m1(strassen(sumMatrix(a11, a22), sumMatrix(b11, b22)));
		vector<vector<int>> m2(strassen(sumMatrix(a21, a22), b11));
		vector<vector<int>> m3(strassen(a11, subMatrix(b12, b22)));
		vector<vector<int>> m4(strassen(a22, subMatrix(b21, b11)));
		vector<vector<int>> m5(strassen(sumMatrix(a11, a12), b22));
		vector<vector<int>> m6(strassen(subMatrix(a21, a11), sumMatrix(b11, b12)));
		vector<vector<int>> m7(strassen(subMatrix(a12, a22), sumMatrix(b21, b22)));

		vector<vector<int>> c11(sumMatrix(subMatrix(sumMatrix(m1, m4), m5), m7));
		vector<vector<int>> c12(sumMatrix(m3, m5));
		vector<vector<int>> c21(sumMatrix(m2, m4));
		vector<vector<int>> c22(sumMatrix(subMatrix(sumMatrix(m1, m3), m2), m6));

		return MatrixSum(c11, c12, c21, c22);
	}
}

int main() {
	vector<vector<int>> A{ { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 1, 2, 3 },{ 4, 5, 6, 7 } };
	vector<vector<int>> B{ { 8, 9, 1, 2 },{ 3, 4, 5, 6 },{ 7, 8, 9, 1 },{ 2, 3, 4, 5 } };

	Matrix matrix(A, B);
	cout << endl << "연산 결과를 확인 합니다." << endl;
	matrix.check(matrix.strassen(A, B));

	vector<vector<int>> A2{ { 6, 7, 5, 9},{ 1, 5, 2, 8 },{ 6, 5, 6, 8 },{ 9, 2, 2, 1} };
	vector<vector<int>> B2{ { 8, 9, 7, 5 },{ 2, 7, 1, 9},{ 6, 3, 1, 1 },{ 3, 4, 1, 2} };

	Matrix matrix2(A2, B2);
	cout << endl << "임의의 데이터 연산 결과를 왁인 합니다." << endl;
	matrix2.check(matrix2.strassen(A2, B2));
	return 0;
}