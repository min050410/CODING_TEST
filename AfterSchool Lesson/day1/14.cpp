#include <iostream>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int t;
int n, ne;

int isPrime(int x) {
    if (x == 1) return 0;
    for (int i=2; i<x; i++) {
        if (x%i==0) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int T=0; T<t; T++) {
        cin >> n;
        while (n) {
            ne = ne * 10 + (n % 10);
            n = n / 10;
        }
        if (isPrime(ne)) {
            cout << ne << ' ';
        }
        ne = 0;
    }
}
