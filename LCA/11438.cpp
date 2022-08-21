// LCA
#include <iostream>
#include <vector>
#define LOG 21 // 2^20 = 1000000

using namespace std;

int n, m;
int parent[100001][21];
int d[100001];
bool v[100001]; // 계산 여부
vector<int> graph[100001];
int a, b;

void SwapValue(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// depth check
void dfs(int x, int depth) {
    v[x] = true;
    d[x] = depth;
    for (int g: graph[x]) {
        if (v[g]) continue;
        parent[g][0] = x;
        dfs(g, depth+1);
    }
}

void set_parent() {
    dfs(1, 0);
    for (int i=1; i<LOG; i++) {
        for (int j=1; j<n+1; j++) {
            // LCA 알고리즘의 핵심 => 2^i번째의 부모를 참조
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}

int lca(int a, int b) {

    // 1. 무조건 b가 더 깊게
    if (d[a] > d[b]) {
        SwapValue(a, b);
    }

    // 2. b와 a의 깊이를 같게
    for (int i=LOG-1; i>=0; i--) {
        if (d[b] - d[a] >= (1 << i)) {
            b = parent[b][i];
        }
    }

    // 3. 여기서 같은 부모이면 return
    if (a == b) {
        return a;
    }

    // 2^i씩 거슬러 올라감 -> 점점 올라가는 폭이 작아짐 O(log n)
    for (int i=LOG-1; i>-1; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }

    // LCA return
    return parent[a][0];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i=0; i<n-1; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    set_parent();

    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
