// ACM CRAFT

// level로 접근할려는 시도는 좋았으나 런타임 에러가 걸림
// 가중치를 더할 때 다익스트라 알고리즘 더하듯 지난 가중치 + 현재 가중치를 해야함


#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int T;
int k, n;
int a, b;
int w[100001];
int buildWin;
int indegree[100001];
int result[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t=0; t<T; t++) {
        vector<int> graph[10001];
        queue<int> q;
        cin >> n >> k;
        // 가중치
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
        }
        // cin
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            indegree[b]++;
        }
        // 승리하기위해 건설해야할 건물의 번호
        cin >> buildWin;
        for (int i=1; i<=n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        // 시작
        while (indegree[buildWin] > 0) {
            int j = q.front();
            q.pop();
            for (const auto &v: graph[j]) {
                // 현재 총 시간 = 지난 시간 + 현재 시간
                result[v] = max(result[v], result[j]+w[j]);
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        cout << result[buildWin]+w[buildWin] << '\n';
        memset(indegree, 0, sizeof(indegree));
        memset(w, 0, sizeof(w));
        memset(result, 0, sizeof(result));
    }
}