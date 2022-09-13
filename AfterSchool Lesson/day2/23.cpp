// 연속된 수 이기 때문에 dp안써도 되는 문제였음

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int n;
int dp[1000001];
int max_int = 1;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i=1; i<n; i++) {
        if (arr[i-1] <= arr[i]) {
            dp[i] = dp[i-1]+1;
            max_int = max(max_int, dp[i]);
        }
        else {
            dp[i]=1;
        }
    }
    cout << max_int;
}