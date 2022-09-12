// 게임 

#include <iostream>
#define ll long long
using namespace std;

ll x;
ll y;
ll z;
ll ans = -1;

int main(){
    cin >> x >> y;
    z = y*100 / x + 1;
    if(z == 100 || z == 101){
        cout << -1;
        return 0;
    }
    ll l = 1;
    ll r = 1000000000;
    while(l <= r){
        ll mid = (l + r) / 2;
        ll val = (y + mid)*100 / (x + mid);
        if(z <= val) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans;
}