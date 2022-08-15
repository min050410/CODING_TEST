// 알고리즘 수업 - 깊이 우선 탐색 2

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 100001

int visited[MAX] = {0,};
int result[MAX];
vector<int> graph[MAX];
int cnt = 0;

bool compare (int a, int b) {
    return a > b;
}

void dfs(int x) {
    if (visited[x] == 1) return ;

    visited[x] = 1;
    cnt++;
    result[x] = cnt;
    for (int i = 0; i < graph[x].size(); i++) {
        dfs(graph[x][i]);
    }
}


int main() {
    int N, M, R;
    cin >> N >> M >> R;
    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }
    dfs(R);
    for (int i = 1; i <= N; i++) {
        cout << result[i];
    }

    return 0;
}