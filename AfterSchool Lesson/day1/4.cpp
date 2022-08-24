#include <iostream>
#include <algorithm>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n;
int a;
int min_age = inf;
int max_age = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        max_age = max(max_age, a);
        min_age = min(min_age, a);
    }
    cout << max_age - min_age;
}