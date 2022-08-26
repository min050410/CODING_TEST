// TLE : O(n)을 O(root n)으로 풀어서 해결함

#include <iostream>
#include <stack>
#include <algorithm>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n, cnt;
int dp[50001];

int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
    cin >> n;
		int cnt = 0;
		for (int N=1; N <= n; N++) {
				for (int i = 1; i * i <= N; i++) {
					if (i * i == N) cnt++;
					else if (N % i == 0) cnt += 2;
				}
				cout << cnt << ' ';
				cnt = 0;
		}
}