// 파티

#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>

using namespace std;

int n, m, cost, e;
int a, b, c, dist, temp;
int dis[20001];
int inf = INT_MAX;
int go, back;
int res;

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
				pq.push(make_pair(cost, ver.second));		
			}
		}
	}
}

void reset(){
	for (int j=1; j<=n; j++){
		dis[j] = inf;
	}
}

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
  ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> e;
	
	for (int i=1; i<=m; i++){
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c, b));
	}
	// 초기화
	reset();
	for (int i=1; i<=n; i++){
		
		dijkstra(i);
		go = dis[e];
		reset();
		dijkstra(e);
		back = dis[i];
		reset();
		res = max(go+back, res);
	}
	
	cout << res; 
}
