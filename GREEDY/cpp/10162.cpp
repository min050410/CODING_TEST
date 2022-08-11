// 전자레인지

#include <iostream>
#define ll long long
#define INF 0xffffff7
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    if (n%10 != 0) {
        cout << -1;
        return 0;
    }
    if (n-300>=0) {
        cout << n/300 << ' ';
        n %= 300;
    }
    else {
        cout << 0 << ' ';
    }
    if (n-60>=0) {
        cout << n/60 << ' ';
        n %= 60;
    }
    else {
        cout << 0 << ' ';
    }
    if (n-10>=0) {
        cout << n/10 << ' ';
        n %= 10;
    }
    else {
        cout << 0;
    }
}