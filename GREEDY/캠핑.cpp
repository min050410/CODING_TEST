// 캠핑
// 휴가 기간 k와 연속하는 m일의 나머지와 나눗셈의 값을 구하고 답과의 관계를 생각하면 쉬운 문제이다.

// 예외: 무조건 k를 m으로 나눈 나머지를 더한다고 답이 되진 않는다. k%m > n일 경우도 생각해야 한다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 0x7fffffff
#define ll long long

using namespace std;
ll n, m, k, t;
vector<int> answer;

void solve() {
    int i=1;
    while (1) {
        cin >> n >> m >> k;
        if (n == 0 && m == 0 && k == 0) return;

        int s;
        s = k/m;
        t = k%m;

        if (t < n) cout << "Case " << i << ": " << s*n+t << '\n';
        else cout << "Case " << i << ": " << s*n+n << '\n';
        i++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

