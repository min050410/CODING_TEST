// 트리의 부모 찾기
// 시간 복잡도 O(v+e)
// bfs를 이용해 간단하게 해결할 수 있다.
// parent배열과 visited배열을 분리해 해결하였지만, 합칠 수도 있을 것 같다.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
int n;
int a, b;
vector<int> v[100001];
int visited[100001];
int parent[100001];

void bfs() {
    visited[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int temp = q.front();
        visited[temp] = 1;
        q.pop();
        for (int i: v[temp]) {
            if (!visited[i]) {
                parent[i] = temp;
                q.push(i);
            }
        }
    }
}



int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs();
    for (int i=2; i<=n; i++) {
        cout << parent[i] << '\n';
    }
}