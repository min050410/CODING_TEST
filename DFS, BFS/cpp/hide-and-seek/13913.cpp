// 숨바꼭질 4

#include <iostream>
#include <queue>

using namespace std;
int n, m;
int visited[1000001];
int parent[10000001];
int s = 100000;
vector<int> v;
queue<pair<int, int>> q;

void bfs() {
    q.push({n, 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int path = q.front().second;

        q.pop();

        // 목표 도달시 break
        if (cur == m) {
            s = path;
            break;
        }

        int mn;
        mn = cur + 1;
        if (mn <= 100100 && !visited[mn]) {
            q.push({mn, path + 1});]
            // parent 배열으로 경로 저장
            parent[mn] = cur;
            visited[mn] = 1;
        }
        mn = cur - 1;
        if (mn >= 0 && !visited[mn]) {
            q.push({mn, path + 1});
            parent[mn] = cur;
            visited[mn] = 1;
        }
        mn = cur * 2;
        if (mn <= 100100 && !visited[mn]) {
            q.push({mn, path + 1});
            parent[mn] = cur;
            visited[mn] = 1;
        }
    }
}

int main() {
    cin >> n >> m;
    bfs();
    cout << s << '\n';
    int idx = m;

    // 경로를 vector에 담기
    while (idx != n) {
        v.push_back(idx);
        idx = parent[idx];
    }

    v.push_back(n);

    // 경로 출력
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i] << ' ';
    }

};