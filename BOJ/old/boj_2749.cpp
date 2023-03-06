#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
long long memo[10000001] = { 0, };

long long fibonacci(long long n) {
	if (n <= 1) {
		return n;
	}
	else if (memo[n] != 0) {
		return memo[n];
	}
	else {
		return memo[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1000000;
	}
}
int main() {
	long long n;
	cin >> n;
    // 피사노 주기
    // N번째 피보나치수를 M으로 나눈 나머지는
    // N(10 ^ k) % P번째 피보나치 수를 M(15*10^(k-1))으로 나눈 나머지와 같다

	cout << fibonacci(n % 1500000) << endl;
	return 0;
}