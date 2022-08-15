// 회의실 배정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a.begin(), a.end());
	int s = 0, 
    ans = 0;
	for (int i = 0; i < n; i++) {
		if (s <= a[i].second) {
			s = a[i].first;
			ans++;
		}
	}
	cout << ans;

}