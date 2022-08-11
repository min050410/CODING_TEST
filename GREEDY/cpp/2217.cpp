// 로프

#include <iostream>
#include <algorithm>
#define ll long long
#define INF 0xffffff7
using namespace std;

int n;
int arr[100001];
int res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for (int i=0; i<n; i++) {
        res = max(res, arr[i] * (n - i));
    }

    cout << res;
}