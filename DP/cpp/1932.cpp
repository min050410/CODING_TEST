// 정수 삼각형 

#include <iostream>

using namespace std;

int n;
int dp[1000][1000];
int tree[1000][1000];
int max_num;

int main() {
    cin >> n;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> tree[i][j];
        }
    }

    dp[1][1] = tree[1][1];

    // bottom-up
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            int prev;
            // 가장 왼쪽
            if (j-1 == 0) {
                prev = dp[i-1][j];
            }
            // 가장 오른쪽
            else if (j == i) {
                prev = dp[i-1][j-1];
            }
            // 위에 2개중 택 1
            else {
                prev = max(dp[i-1][j], dp[i-1][j-1]);
            }
            dp[i][j] = max(dp[i][j], prev+tree[i][j]);
            max_num = max(max_num, dp[i][j]);
        }
    }

    cout << max_num;
}