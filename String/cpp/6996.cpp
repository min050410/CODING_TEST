// 애너그램

#include <iostream>
#include <cstring>
using namespace std;

int n;
string a, b;
int cnt[1000001];
int cnt2[1000001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        for (int j=0; j<a.size(); j++) {
            cnt[a[j]-'0']++;
        }
        for (int j=0; j<b.size(); j++) {
            cnt2[b[j]-'0']++;
        }
        int flag = 1;
        for (int j=0; j<1000; j++) {
            if (cnt[j] != cnt2[j]) {
                flag = 0;
            }
        }
        if (flag) {
            cout << a << " & " << b << " are anagrams." << '\n';
        }
        else {
            cout << a << " & " << b << " are NOT anagrams." << '\n';
        }
        memset(cnt, 0, sizeof(cnt));
        memset(cnt2, 0, sizeof(cnt2));
    }
}