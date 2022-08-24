#include <iostream>
#include <stack>
#include <algorithm>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n, cnt;

int main() {
    cin >> n;
    for (int k=1; k<=n; k++) {
        for (int i = 1; i <= k; i++) {
            if (k % i == 0) {
                cnt++;
            }
        }
        cout << cnt << ' ';
        cnt = 0;
    }
}
