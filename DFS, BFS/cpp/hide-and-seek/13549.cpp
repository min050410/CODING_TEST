// 숨바꼭질 3

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

//        if (s < path) {
//            break;
//        }

        // 최소 시간 구하기 
        if (cur == m) {
            s = min(s, path);
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
            // 숨바꼭질 2와 다르게 0으로 바뀜
            q.push({mn, path + 0});
        }
    }
}

int main() {
    cin >> n >> m;
    bfs();
    cout << s;
}