#include<iostream>

using namespace std;

int n, m;
int cnt;

int main() {
    cin >> n >> m;
    for (int i=m; i<=n; i+=m) {
        cnt += i;
    }
    cout << cnt;
}