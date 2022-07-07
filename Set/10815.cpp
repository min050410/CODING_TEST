// 숫자 카드

#include <iostream>
#include <map>
#include <set>

using namespace std;

set<int> s;
int n;
int a;

int n2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        s.insert(a);
    }
    cin >> n2;
    for (int i=0; i<n2; i++) {
        cin >> a;
        if (s.find(a)!=s.end()) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }
}