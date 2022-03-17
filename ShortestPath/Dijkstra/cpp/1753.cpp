#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m, start, cost;
int a, b, c, dist, temp;
int dis[20001];
int inf = INT_MAX;

vector<pair<int, int>> v[20005];
// min priority_queue
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;


void dijkstra(int start){
	pq.push(make_pair(0, start));
	// 자기 자신은 0으로
	dis[start] = 0;
	// queue가 빌때까지
	while (!pq.empty()){
		// queue에서 front 꺼내고 pop
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
				// 여기서 실수함 ( ㅠㅠ 하루종일 헤맸다 )
				pq.push(make_pair(cost, ver.second));		
			}
		}
	}
}

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
  ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	cin >> start;
	
	for (int i=1; i<=m; i++){
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c, b));
	}

	// 모든 값을 무한으로 초기화
	for (int i=1; i<=n; i++){
		dis[i] = inf;
	}
	dijkstra(start);

	for (int i=1; i<=n; i++){
		if (dis[i] == inf)
		{
			cout << "INF" << '\n';
		}
		else{
			cout << dis[i] << '\n';
		}
	}
}