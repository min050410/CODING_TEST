// 연결 요소의 개수

#include <iostream>
#include <vector>
#define inf 0xfffffff7
#define ll long long

using namespace std;

int n, m;
int a, b;
int cnt;
vector<int> v[100000];
int visited[100000];

void dfs(int x) {
    if (visited[x]) return;
    visited[x] = 1;
    for (int vec: v[x]) {
        dfs(vec);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}