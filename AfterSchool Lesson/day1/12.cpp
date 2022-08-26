#include <iostream>
#include <algorithm>

#define ll long long
#define inf 0x7fffffff

using namespace std;

int cnt;
int n;
int dp[100000001];
int temp_cnt;

int main() {
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
    cin >> n;
		for (int i=1; i<=9; i++) {
			dp[i] = 1;
			cnt+=dp[i];
		}
    for (int i=10; i<=n; i++) {
			if (dp[i/1000000]) {
				dp[i]=dp[i/1000000]+6;
				cnt+=dp[i];
				continue;
			}
			if (dp[i/100000]) {
				dp[i]=dp[i/100000]+5;
				cnt+=dp[i];
				continue;
			}
			if (dp[i/10000]) {
				dp[i]=dp[i/10000]+4;
				cnt+=dp[i];
				continue;
			}
			if (dp[i/1000]) {
				dp[i]=dp[i/1000]+3;
				cnt+=dp[i];
				continue;
			}
			if (dp[i/100]) {
				dp[i]=dp[i/100]+2;
				cnt+=dp[i];
				continue;
			}
			if (dp[i/10]) {
				dp[i] = dp[i/10]+1;
				cnt+=dp[i];
				continue;
			}
    }
    cout << cnt;
}
