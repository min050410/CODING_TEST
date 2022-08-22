// 나무 자르기

#include <iostream> 
#define ll long long
using namespace std;

ll n, m;
ll arr[1000001];
ll max_height, min_height;

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> arr[i];
		max_height = max(max_height, arr[i]); 
	}
	while (min_height < max_height) {
		ll mid = (max_height + min_height) >> 1;
		ll cnt = 0;
		for (const auto &a: arr) {
			if (a - mid > 0) {
				cnt += (a-mid);
			}
		}
		if (cnt < m) {
			max_height = mid;
		}
		else {
			min_height = mid + 1;
		}

	}
	cout << min_height - 1;
}
