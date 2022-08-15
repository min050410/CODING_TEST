// 섬의 개수

#include <iostream>
#include <queue>
#include <cstring>

// 방문 2
// 방문 x 1
// 바다 0

using namespace std;

int n, m;
int res;
int xx[8] = {0, 1, 0, -1, 1, -1, -1, 1};
int xy[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int map[1001][1001];
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int prevX = q.front().first;
        int prevY = q.front().second;
        if (map[prevX][prevY] == 1) {
            res++;
        }
        for (int i=0; i<8; i++) {
            int newX = prevX + xx[i];
            int newY = prevY + xy[i];
            if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
            if (map[newX][newY] == 1) {
                map[newX][newY] = 2;
                q.push({newX, newY});
            }
        }
        q.pop();
    }
}


int main() {

    while(1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1) {
                    q.push({i, j});
                    bfs();
                }
            }
        }

//    for (int i=0; i<m; i++) {
//        for (int j=0; j<n; j++) {
//            cout << map[i][j] << ' ';
//        }
//        cout << '\n';
//    }

        cout << res << '\n';
        memset(map, 0, sizeof(map));
        res = 0;
    }
}