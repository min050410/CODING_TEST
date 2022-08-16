// 안전 영역

#include <iostream>
#include <queue>
#include <algorithm>
#define inf 0xfffffff7

using namespace std;

int n;
int res;
int max_res;
int maxLevel;
int xx[4] = {0, 1, 0, -1};
int xy[4] = {1, 0, -1, 0};
int map[1001][1001];
int map_copy[1001][1001];
queue<pair<int, int>> q;

void copy() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map_copy[i][j] = map[i][j];
        }
    }
}

void bfs(int t) {
    while (!q.empty()) {
        int prevX = q.front().first;
        int prevY = q.front().second;
        if (map_copy[prevX][prevY] > t) {
            res++;
        }
        for (int i=0; i<4; i++) {
            int newX = prevX + xx[i];
            int newY = prevY + xy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if (map_copy[newX][newY] > t) {
                map_copy[newX][newY] = 0;
                q.push({newX, newY});
            }
        }
        q.pop();
    }
}

int main() {

        cin >> n;

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cin >> map[i][j];
                    maxLevel = max(maxLevel, map[i][j]);
                 }
        }

        copy();
        for (int t = maxLevel; t >= 1; t--) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map_copy[i][j] > t) {
                        q.push({i, j});
                        bfs(t);
                    }
                }
            }
            copy();
            max_res = max(max_res, res);
            res = 0;
        }
        if (max_res == 0)
            cout << max_res+1;
        else 
            cout << max_res;
}