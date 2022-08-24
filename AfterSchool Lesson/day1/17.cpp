#include <iostream>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int t;
int n, ans;
int up;

int main() {
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> ans;
        if (n%2==0) up = ((n+1)*n)/2;
        else up = ((n*(n-1))/2)+n;
        if (ans == up) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        up = 0;
    }
}
