// 부분합
// O(n)의 시간 복잡도

#include<iostream>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n, m;
int arr[1000000];
int sum_num;
int min_num = inf;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int e = 0;
    int s = 0;

    while (e <= n) {
        if (sum_num >= m) {
            min_num = min(min_num, e-s);
            sum_num -= arr[s++];
        }
        else if (sum_num <= m) {
            sum_num += arr[e++];
        }
    }

    if (min_num == inf) cout << 0;
    else cout << min_num;
}