// 쉬운 계단 수
// %100... 을 해줘야함

#include <iostream>
#define ll long long
using namespace std;

ll dp[10000][1000];
int n;
ll ans;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    // dp 테이블 row 1 설정
    for (int i=0; i<=9; i++) {
        if (i == 0) {
            dp[1][i] = 0;
        }
        else {
            dp[1][i] = 1;
        }
    }

    // bottom up
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j+1];
            }
            else if (j == 9) {
                dp[i][j] = dp[i-1][j-1];
            }
			else {
				// 점화식
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
			}
        }
    }

	
    for (int i=0; i<=9; i++) {
        ans += dp[n][i] % 1000000000;
    }
    cout << ans % 1000000000;
}