// 특정한 최단 경로

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int n, m, cost;
int a, b, c;
int dis[20001];
int inf = INT_MAX;
int a1, b1;
int n_distance;
int a1_first_distance, b1_first_distance;
int res;

vector<pair<int, int>> v[20005];
// min priority_queue
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;


void dijkstra(int start){
    pq.push(make_pair(0, start));
    dis[start] = 0;
    // queue 가 빌 때까지
    while (!pq.empty()){
        // queue 에서 front 꺼내고 pop
        pair<int,int> temp = pq.top();
        pq.pop();
        // second -> node / first -> cost
        if (dis[temp.second] < temp.first){
            continue;
        }
        for (const auto &ver:v[temp.second]){
            cost = ver.first + dis[temp.second];
            if (cost < dis[ver.second]){
                dis[ver.second] = cost;
                pq.push(make_pair(cost, ver.second));
            }
        }
    }
}

void distance_array_reset(){
    for (int j=1; j<=n; j++){
        dis[j] = inf;
    }
}

int main(){

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i=1; i<=m; i++){
        cin >> a >> b >> c;
        // 양방향
        v[a].push_back(make_pair(c, b));
        v[b].push_back(make_pair(c, a));
    }

    // 초기화
    distance_array_reset();

    cin >> a1 >> b1;

    // 1번 노드 부터 n 노드 까지
    dijkstra(1);
    n_distance = dis[n];
    distance_array_reset();
    if (n_distance == inf){
        cout << -1;
        return 0;
    }

    // start -> a1 -> b1 -> end
    dijkstra(1);
    a1_first_distance = dis[a1];
    distance_array_reset();
    dijkstra(a1);
    a1_first_distance+= dis[b1];
    distance_array_reset();
    dijkstra(b1);
    a1_first_distance+= dis[n];
    distance_array_reset();

    // start -> b1 -> a1 -> end
    dijkstra(1);
    b1_first_distance = dis[b1];
    distance_array_reset();
    dijkstra(b1);
    b1_first_distance+= dis[a1];
    distance_array_reset();
    dijkstra(a1);
    b1_first_distance+= dis[n];
    distance_array_reset();

    res = min(a1_first_distance, b1_first_distance);
    cout << res;
}