#include<iostream>
#define ll long long

using namespace std;

int n, m;
int cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=n; i<m; i++) {
        cout << i << " +";
        cnt += i;
    }
    cout << m << " = " << cnt+m;
}