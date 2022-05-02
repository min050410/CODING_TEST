// 수들의 합

#include <iostream>
using namespace std;

int a[10000];
int n, m;
int cnt;

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	int start = 0, end = 0;
	int p_sum = 0;
	while (end <= n){
		if (p_sum >= m){
			p_sum -= a[start++];
		}
		else if (p_sum < m){
			p_sum += a[end++];
		}
		if (p_sum == m){
			cnt++;
		}
	}
	cout << cnt;
}