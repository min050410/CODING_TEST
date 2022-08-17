// 커트라인

#include <iostream>
#include <queue>
#define ll long long
using namespace std;

priority_queue<int> pq;
int n, m;
int a, ans;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a;
        pq.push(a);
    }

    for (int i=0; i<m; i++) {
        ans = pq.top();
        pq.pop();
    }

    cout << ans;
}