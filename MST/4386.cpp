// 별자리만들기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int parent[1000000];
int n, m;
float a, b, w;
//int a, b, w;
pair<float, float> v[100000];

class Edge {
public:
    int vtx[2];
    float distance;
    Edge(int a, int b) {
        this->vtx[0] = a;
        this->vtx[1] = b;
        this->distance = sqrt(pow(v[a].first - v[b].first, 2) + pow(v[a].second - v[b].second,2));
    }
    bool operator <(Edge& edge) {
        return this->distance < edge.distance;
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

    cin >> n;
    vector<Edge> data;

    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            data.emplace_back(i, j);
        }
    }

    sort(data.begin(), data.end());

    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    float sum = 0;

    for (int i=0; i < data.size(); i++) {
        if (!find(data[i].vtx[0], data[i].vtx[1])) {
            sum += data[i].distance;
            Union(data[i].vtx[0], data[i].vtx[1]);
        }
    }

    cout << sum;
}