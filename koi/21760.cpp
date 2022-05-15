// 야구시즌

#include <iostream>
#include <cmath>

using namespace std; 

#define INF 7fffffff
#define ll long long

ll a, b;
ll N, M, k, D;
ll ans;
ll T;


ll fac(ll x) {
    ll res = 1;
    while(x) {
        res *= x; 
        x--;
    }
    return res;
}

int main () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;
    for (ll t = 0; t < T; t++){
        cin >> N >> M >> k >> D;
        ll A = 0;
        ll B = 0;
        while (a + b <= D){
            A += k;
            B++;

            a = (N * (M*(M-1)))/2 * A;
            b = N*M*M*(N-1)/2*B;

            if (a + b <= D){
                ans = a + b;
            }
        }
        if (ans == 0){
            cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
        a = 0;
        b = 0;
        ans = 0;
    }
    return 0;
}