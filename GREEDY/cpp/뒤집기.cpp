// 뒤집기
// 뒤집는 횟수가 0, 1 그룹의 개수 / 2 인 점을 이용하여서 푼 문제이다.
// 만약 '00110011'이라면 0, 1 그룹의 개수는 총 4개이고 /2를 하면 2가 나와서 뒤집어야 하는 개수는 2이다. 


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 0x7fffffff
#define ll long long

using namespace std;
string s;
int cnt = 1;

void solve() {
    cin >> s;
    int first = (s[0] == '0') ? 0:1;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '0') {
            if (first == 1) {
                cnt++;
                first = 0;
            }
        }
        if (s[i] == '1') {
            if (first == 0) {
                cnt++;
                first = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    cout << cnt / 2;
    return 0;
}

