// 특정 경로 찾기

#include <iostream>
#include <queue>
#define INF 0x7fffffff

using namespace std;

vector<int> v[3000000];
int dis[3000000];
int n, m, k, x;
int a, b;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void dijkstra(int s){
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (const auto &next: v[cur]){
            if (dis[next] > w + 1){
                dis[next] = w + 1;
                pq.push({dis[next], next});
            }
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k >> x;

    for (int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
    }

    for (int i=1; i<=n; i++){
        dis[i] = INF;
    }

    dijkstra(x);

//    for (int i=1; i<=n; i++){
//        cout << dis[i] << '\n';
//    }

    int flag = 0;
    for (int i=1; i<=n; i++){
        if (dis[i] == k){
            cout << i << '\n';
            flag = 1;
        }
    }
    if (!flag){
        cout << -1;
    }

}