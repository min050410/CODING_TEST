// 두 용액

#include <iostream>
#include <algorithm>
#define INF 0x7fffffff

using namespace std;

int n;
int a[100000];
int res[2];

int main() {
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	// 정렬
	sort(a, a+n);

	int start = 0;
	int end = n-1;
	int sum = 0;
	int m = INF;
	while (start < end){
		sum = a[start] + a[end];
		if (m > abs(sum)) {
			m = abs(sum);
			res[0] = a[start];
			res[1] = a[end];
		}
		if (m == 0){
			break;
		}
		if (sum < 0) {
			start++;
		}
		else {
			end--;
		}
	}
	cout << res[0] << " " << res[1];
}