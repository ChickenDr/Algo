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

	cout << "�������� �Է��ϼ���.: ";
	cin >> num1;
	cout << "������ �Է��ϼ���.: ";
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
		cout << "0�� �ԷµǾ����ϴ�." << endl;
		cout << "���α׷��� ����˴ϴ�." << endl;
	}
	return 0;
}
