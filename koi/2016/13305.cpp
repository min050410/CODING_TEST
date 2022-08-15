// 주유소

#include <iostream>
#include <algorithm>
#define ll long long
#define INF 0xffffff7
using namespace std;

ll n;
ll a[100001];
ll b[100001];
ll cost = 1000000000;
ll cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    for (int i=0; i<n; i++) {
        cost = min(cost, b[i]);
        cnt += cost * a[i];
    }
    cout << cnt;
}