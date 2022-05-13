// 세 용액

#include <iostream>
#include <algorithm>
// ll 자료형이기 때문에 INF 의 범위도 늘려줘야됨
#define INF 0x7ffffffffff
#define ll long long

using namespace std;

ll n;
ll a[1000000];
ll res[3];

int main() {
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    // 정렬
    sort(a, a+n);

    ll sum = 0;
    ll m = INF;
    for (ll i=0; i<n-2; i++){
        ll start = i+1;
        ll end = n-1;
        while (start < end){
            sum = a[start] + a[i] + a[end];
            if (m > abs(sum)) {
                m = abs(sum);
                res[0] = a[start];
                res[1] = a[i];
                res[2] = a[end];
            }
            if (m == 0){
                break;
            }
            if (sum < 0) {
                start++;
            }
            else {
                end--;
            }
        }
    }
    cout << res[1] << " " << res[0] << " " << res[2];
}