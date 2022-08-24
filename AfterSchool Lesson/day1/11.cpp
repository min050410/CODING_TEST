#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define inf 0x7fffffff

using namespace std;

int cnt;
int n;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int temp = i;
        while (temp) {
            cnt++;
            temp = temp / 10;
        }
    }
    cout << cnt;
}
