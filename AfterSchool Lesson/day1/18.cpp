#include <iostream>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n, m;
int a;
int max_cnt;

int main() {
    cin >> n >> m;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cin >> a;
        if (a > m) {
            cnt++;
            max_cnt = max(max_cnt, cnt);
        }
        else {
            cnt = 0;
        }
    }
    cout << max_cnt;
}
