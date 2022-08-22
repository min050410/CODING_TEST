// 사이클 게임

#include <iostream>
using namespace std;

#define inf 0x7fffffff
#define ll long long

int n, m;
int parent[500001];
int node1, node2;

int Find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

int Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    // 사이클
    if (a == b) return 1;
    if (a > b) {parent[a] = b; return 0;}
    else {parent[b] = a; return 0;}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> node1 >> node2;
        if(Union(node1, node2)) {
            cout << i+1;
            return 0;
        }
    }
    cout << 0;
}


