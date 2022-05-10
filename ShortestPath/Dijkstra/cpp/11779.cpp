// 최소비용구하기 2

#include <iostream>
#include <queue>
#include <vector>
#define INF 0x7fffffff

using namespace std;

vector<pair<int, int>> v[3000000];
int dis[3000000];
int n, m;
int s, e;
int a, b, c;
int cnt;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
vector<int> through[3000000];

void dijkstra(int s){
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        // 시간 줄이기
        if (w > dis[cur]){
            continue;
        }
        for (const auto &next: v[cur]){
            if (dis[next.second] > w + next.first){

                // 지난 경로 삽입
                through[next.second] = {};
                for (const auto &last: through[cur]){
                    through[next.second].push_back(last);
                }
                through[next.second].push_back(cur);

                dis[next.second] = w + next.first;
                pq.push({dis[next.second], next.second});
            }
        }
    }
}

int main() {

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        v[a].push_back({c, b});
    }

    for (int i=1; i<=n; i++){
        dis[i] = INF;
    }

    cin >> s >> e;

    dijkstra(s);

//    for (int i=1; i<=n; i++){
//        cout << dis[i] << '\n';
//    }
    cout << dis[e] << '\n';

    cout << through[e].size() + 1 << '\n';

    for (const auto &res: through[e]) {
        cout << res << " ";
    }
    cout << e;
}
