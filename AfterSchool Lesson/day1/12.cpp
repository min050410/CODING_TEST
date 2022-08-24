#include <iostream>
#include <algorithm>

#define ll long long
#define inf 0x7fffffff

using namespace std;

int cnt;
int n;
int dp[100000];
int temp_cnt;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int temp = i;
        if (dp[i/10]) dp[i] = dp[i/10]+1;
        while (temp) {
            cnt++;
            temp_cnt++;
            temp = temp / 10;
        }
        dp[i] = temp_cnt;
        temp_cnt = 0;
    }
    cout << cnt;
}
