#include <iostream>

using namespace std;

void divide(int num1, int num2, int *q, int *r)
{
	*q = num1 / num2;
	*r = num1 % num2;
}

int main(void)
{
	int num1, num2;
	int q, r;

	cout << "피제수를 입력하세요.: ";
	cin >> num1;
	cout << "제수를 입력하세요.: ";
	cin >> num2;
	try
	{
		if (num2 == 0)
			throw num2;
		divide(num1, num2, &q, &r);
		cout << num1 << "/" << num2 << "=" << q << endl;
		cout << num1 << "%" << num2 << "=" << r << endl;
	}
	catch (int expn)
	{
		cout << "0이 입력되었습니다." << endl;
		cout << "프로그램이 종료됩니다." << endl;
	}
	return 0;
}
