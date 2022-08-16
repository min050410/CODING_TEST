// 숨바꼭질

#include <iostream>
#include <queue>

using namespace std;
int n, m;
int visited[1000001];
queue<int> q;

void bfs() {
    visited[n] = 1;
    q.push(n);
    while (!q.empty()) {
        if (q.front() == m) {
            // visited 배열 출력 
            // dp memo 배열의 역할을 함
            cout << visited[q.front()] - 1;
            break;
        }
        int mn;
        mn = q.front() + 1;
        if (mn >= 0 && mn <=100100 && !visited[mn]) {
            q.push(mn);
            // 시간을 visited 배열에 저장
            visited[mn] = visited[q.front()] + 1;
        }
        mn = q.front() - 1;
        if (mn >= 0 && mn <=100100 && !visited[mn]) {
            q.push(mn);
            visited[mn] = visited[q.front()] + 1;
        }
        mn = q.front() * 2;
        if (mn >= 0 && mn <=100100 && !visited[mn]) {
            q.push(mn);
            visited[mn] = visited[q.front()] + 1;
        }
        q.pop();
    }
}

int main() {
    cin >> n >> m;
    bfs();
}