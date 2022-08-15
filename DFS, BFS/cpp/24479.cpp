// 알고리즘 수업 - 깊이 우선 탐색 1

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, R;
int u, v;

vector<int> graph[100001];
int visited[100001];
int result[100001];
int cnt = 0;

void dfs(int x) {
	if (visited[x] == 1) {
		return;
	}

	visited[x] = 1;
	cnt++;
	result[x] = cnt;

	for (int i = 0; i < graph[x].size(); i++) {
		dfs(graph[x][i]);
	}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> N >> M >> R;
	for (int i = 1; i <= M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(R);
	for (int i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}
	
}