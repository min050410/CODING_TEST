// 나머지 합

#include <iostream>
#define ll long long
using namespace std;

ll arr[1000000];
ll ans[1000000];
ll n, m;
ll cnt;

int main(){

    cin >> n >> m;

    for (int i = 1;i <= n; i++){

        cin >> arr[i];
        // prefix sum 계산
        arr[i] += arr[i-1];
        // 나머지를 미리 구한 것과 후에 구한 것은 차이가 없음 (분배법칙)
        arr[i] %= m;
        ans[arr[i]]++;
        // 바로 나누어 떨어지는 경우
        if (arr[i] == 0) cnt++;
    }

    for (int i=0; i<=n; i++) {
        // 경우의 수
        cnt += ans[i] * (ans[i]-1) / 2;
    }

    cout << cnt;

    return 0;
}