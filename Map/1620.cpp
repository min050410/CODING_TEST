// 나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <map>

using namespace std;

map<string, int> m;
int n, n2;
string a;
string m2[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> n2;
    for (int i=1; i<=n; i++) {
        cin >> a;
        m.insert({a, i});
        m2[i] = a;
    }
    for (int i=0; i<n2; i++) {
        cin >> a;
        // int 자료형 변환
        int l = atoi(a.c_str());
        if (l == 0) {
            cout << m[a] << '\n';
        }
        else {
            cout << m2[l] << '\n';
        }
    }
}