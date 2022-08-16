// 숨바꼭질 2

#include <iostream>
#include <queue>
#define inf 0xfffffff7

using namespace std;
int n, m;
int cnt;
int visited[1000001];
int s = 100000;
queue<pair<int, int>> q;

void bfs() {
    q.push({n, 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int path = q.front().second;
        
        q.pop();

        visited[cur] = 1;

        // 가장 짧은 시간보다 현재 시간이 더 크면 break
        if (s < path) {
            break;
        }

        // 동시에 도달했을 때
        if (cur == m) {
            s = path;
            cnt++;
            continue;
        }

        int mn;
        mn = cur + 1;
        if (mn <= 100100 && !visited[mn]) {
            q.push({mn, path + 1});
        }
        mn = cur - 1;
        if (mn >= 0 && !visited[mn]) {
            q.push({mn, path + 1});
        }
        mn = cur * 2;
        if (mn <= 100100 && !visited[mn]) {
            q.push({mn, path + 1});
        }
    }
}

int main() {
    cin >> n >> m;
    bfs();
    cout << s << ' ' << cnt;
}