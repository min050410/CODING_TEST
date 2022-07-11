// 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1000000];
int n, m;
int a, b, w;

// 간선 정보 클래스
class Edge {
public:
    int vtx[2]; // 연결된 2개의 정점
    int distance; // 거리(비용)
    Edge(int a, int b, int distance) {
        this->vtx[0] = a;
        this->vtx[1] = b;
        this->distance = distance;
    }
    bool operator <(Edge& edge) {
        return this->distance < edge.distance; // 적은 거리 우선 정렬
    }
};


int findParent (int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = findParent(parent[x]);
    }
}

void Union(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

int find(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a == b) {
        return 1;
    }
    else {
        return 0;
    }
}

int main () {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    vector<Edge> data;
    for (int i=0; i<m; i++) {
        cin >> a >> b >> w;
        data.emplace_back(a, b, w);
    }
    sort(data.begin(), data.end());

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    int sum = 0;\

    for (int i=0; i < data.size(); i++) {
        // 사이클 아니면
        if (!find(data[i].vtx[0], data[i].vtx[1])) {
            sum += data[i].distance;
            Union(data[i].vtx[0], data[i].vtx[1]);
        }
    }
    cout << sum;
}