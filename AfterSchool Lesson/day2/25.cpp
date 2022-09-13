#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int, int>> pq;
int n, a;
int ans[100000];

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a;
        pq.push({a, i});
    }

    // 같은거 고려
    int score1 = 1;
    // 같은거 비고려 무조건 증가
    int score2 = 1;
    int before = 0;
    while (!pq.empty()) {
        if (before == pq.top().first) {
            ans[pq.top().second] = score1-1;
            score2++;
        }
        else {
            ans[pq.top().second] = score2;
            score1 = ++score2;
        }
        before = pq.top().first;
        pq.pop();
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }

}