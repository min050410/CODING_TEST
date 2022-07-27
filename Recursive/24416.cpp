// 알고리즘 수업 - 피보나치 수 1

#include <iostream>
using namespace std;
#define long long ll;

ll fib[41];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fib[1] = fib[2] = 1;
	for (int i = 3; i < 41; i++) fib[i] = fib[i - 1] + fib[i - 2];

	int N; cin >> N;
	cout << fib[N] << ' ' << N - 2;
}