// A -> B
// A를 B로 바꾸는 과정을 bfs를 이용해 최솟값을 구했다.
// 연산한 횟수를 queue pair의 오른쪽, 연산 결과를 queue pair의 왼쪽으로 배치했다.

// 예외 : ll 자료형으로 변환

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define inf 0x7fffffff
#define ll long long

using namespace std;
ll n, m;
string s;
queue<pair<ll, ll>> q;
ll result = inf;

void bfs(ll a) {
    q.push({a, 1});
    while (!q.empty()) {
        ll temp = q.front().first;
        ll x = q.front().second;
        q.pop();
        if (temp > m) continue;
        if (temp == m) {
            result = min(x, result);
        }
        for (int i=0; i<2; i++) {
            ll next = 0;
            if (i == 0) next = temp*2;
            else next = (temp*10)+1;
            q.push({next, x+1});
        }
    }
}

void solve() {
    cin >> n >> m;
    bfs(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    if (result == inf) cout<<-1;
    else cout << result;
    return 0;
}

