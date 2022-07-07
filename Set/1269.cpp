// 대칭 차집합

#include <iostream>
#include <set>

using namespace std;

set<int> s;
set<int> s2;
int n, m;
int a;
int cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;
    for (int i=0; i<n; i++) {
        cin >> a;
        s.insert(a);
    }
    for (int i=0; i<m; i++) {
        cin >> a;
        s2.insert(a);
    }
    for (const auto &res: s) {
        if (s2.find(res)==s2.end()) {
            cnt++;
        }
    }
    for (const auto &res: s2) {
        if (s.find(res)==s.end()) {
            cnt++;
        }
    }
    cout << cnt;
}