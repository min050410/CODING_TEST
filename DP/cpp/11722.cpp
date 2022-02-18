// 가장 긴 증가하는 부분 수열
#include <iostream>
using namespace std;

int arr[1001], dp[1001], ans, N;
//dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        int here = 0;
        for(int j = 1; j < i; j++) {
            if(arr[i] < arr[j])
                here = max(here, dp[j]);
        }
        dp[i] = here + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}



