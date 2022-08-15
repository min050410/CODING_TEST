// 수들의 합

#include <iostream>
#define ll long long
#define INF 0xffffff7
using namespace std;

ll n;
ll a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (ll i=1; i<=n; i++) {
        if (i%2==1) {
            a = ((i+1)*(((i+1)/2)-1)) + ((i+1)/2);
        }
        else {
            a = (i+1)*(i/2);
        }
        if (a > n) {
            cout << i-1;
            break;
        }
    }
}