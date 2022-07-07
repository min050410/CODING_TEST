// 문자열 집합

#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> s;
int n, m;
string a;
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
        if (s.find(a)!=s.end()) {
            cnt++;
        }

    }
    cout << cnt;
}