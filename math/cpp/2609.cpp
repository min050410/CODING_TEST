// 최대공약수와 최소공배수

#include <iostream>
#include <algorithm>
#define ll long long
#define inf 0xffffff7

using namespace std;

ll n, m;
ll ans=1;

int main(){

    cin >> n >> m;
    for (int i=1; i<=max(n, m); i++) {
        if (n%i == 0 && m%i == 0) {
            ans = i;
        }
    }
    // 최대공약수 * 최소공배수 = m * n
    cout << ans << '\n' << n*m/ans;
    return 0;
}