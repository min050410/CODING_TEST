// 수열

#include <iostream>
#include <vector>
using namespace std;

int arr[100000];
int n, m;
int ans = -1000000;

int main(){

    cin >> n >> m;

    for (int i = 1;i <= n; i++){
        cin >> arr[i];
        // prefix sum 계산
        arr[i] += arr[i-1];
    }

    for (int i = 0; i <= n-m; i++){
        // 최대 구하기
        ans = max(ans, arr[i+m]-arr[i]);
    }

    cout << ans;
    return 0;
}