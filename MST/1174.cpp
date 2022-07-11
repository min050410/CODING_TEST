// 우주신과의 교감
// 틀린이유 : 1. ll을 써야 했음
//           2. 소수점 2번째 자리까지만 출력 해야 되는 문제 (precision 함수 사용)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

ll parent[1000000];
ll n, m;
long double a, b, w;
ll n1, n2;
//int a, b, w;
pair<long double, long double> v[100000];

class Edge {
public:
    ll vtx[2];
    long double distance;
    Edge(ll a, ll b) {
        this->vtx[0] = a;
        this->vtx[1] = b;
        this->distance = sqrt(pow(v[a].first - v[b].first, 2) + pow(v[a].second - v[b].second,2));
    }
    bool operator <(Edge& edge) {
        return this->distance < edge.distance;
    }
};


ll findParent (ll x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = findParent(parent[x]);
    }
}

void Union(ll a, ll b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}

ll find(ll a, ll b) {
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

    for (ll i=1; i<=n; i++) {
        cin >> a >> b;
        v[i] = {a, b};
    }

    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<=n; j++) {
            data.emplace_back(i, j);
        }
    }

    sort(data.begin(), data.end());

    for (ll i=1; i<=n; i++) {
        parent[i] = i;
    }

    for (ll i=0; i<m; i++) {
        cin >> n1 >> n2;
        Union(n1, n2);
    }

    long double sum = 0;

    for (ll i=0; i < data.size(); i++) {
        if (!find(data[i].vtx[0], data[i].vtx[1])) {
            sum += data[i].distance;
            Union(data[i].vtx[0], data[i].vtx[1]);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << sum << endl;
}