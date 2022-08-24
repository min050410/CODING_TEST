#include<iostream>
#define ll long long

using namespace std;

int n, m;
int cnt = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++) {
        if (i == 1) {
            cout << i;
            continue;
        }
        if (n%i==0) {
            cout << " + " << i;
            cnt += i;
        }
    }
    cout << " = " << cnt;
}