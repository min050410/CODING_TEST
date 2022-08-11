// 보물

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1000];
int b[1000];
int cnt;

bool desc(int a, int b){
    return a > b;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    sort(b, b+n, desc);
    for (int i=0; i<n; i++) {
        cnt = cnt + (a[i] * b[i]);
    }
    cout << cnt;
}