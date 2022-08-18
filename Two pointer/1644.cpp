// 소수의 연속합

#include<iostream>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n, m;
int cnt;
int arr[10000000];
int sum_num;
int min_num = inf;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    // 에라토스테네스의 체
    for (int i=1; i<=n; i++) {
        arr[i] = i;
    }

    for (int i=2; i<=n; i++) {
        for (int j=2*i; j<=n; j+=i) {
            arr[j] = 0;
        }
    }

    // 1은 소수가 아님
    arr[1] = 0;

//    for (int i=1; i<=n; i++) {
//        cout << arr[i] << ' ';
//    }
//    cout << '\n';

    int e = 0;
    int s = 0;

    while (e <= n+1 && s <= n+1) {
        // 0은 소수가 아닌 합성수므로 제외해줘야함
        if (arr[e] == 0 && e != n+1) {
            e++;
            continue;
        }
        if (arr[s] == 0 && s != n+1) {
            s++;
            continue;
        }

        if (sum_num >= n) {
            sum_num -= arr[s++];
        }
        else if (sum_num < n) {
            sum_num += arr[e++];
        }
        
        // 소수들의 합이 n인 경우
        if (sum_num == n) {
            cnt++;
        }
    }

    cout << cnt;
}