// 적록색약

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int res, res2;
int xx[4] = {0, 1, 0, -1};
int xy[4] = {1, 0, -1, 0};
string s;
char map[1001][1001];
char map2[1001][1001];
queue<pair<int, int>> q;

void bfsR() {
    while (!q.empty()) {
        int prevX = q.front().first;
        int prevY = q.front().second;
        if (map[prevX][prevY] == 'R') {
            res++;
        }
        for (int i=0; i<4; i++) {
            int newX = prevX + xx[i];
            int newY = prevY + xy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if (map[newX][newY] == 'R') {
                map[newX][newY] = 'A';
                q.push({newX, newY});
            }
        }
        q.pop();
    }
}

void bfsG() {
    while (!q.empty()) {
        int prevX = q.front().first;
        int prevY = q.front().second;
        if (map[prevX][prevY] == 'G') {
            res++;
        }
        for (int i=0; i<4; i++) {
            int newX = prevX + xx[i];
            int newY = prevY + xy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if (map[newX][newY] == 'G') {
                map[newX][newY] = 'S';
                q.push({newX, newY});
            }
        }
        q.pop();
    }
}

void bfsB() {
    while (!q.empty()) {
        int prevX = q.front().first;
        int prevY = q.front().second;
        if (map[prevX][prevY] == 'B') {
            res++;
        }
        for (int i=0; i<4; i++) {
            int newX = prevX + xx[i];
            int newY = prevY + xy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if (map[newX][newY] == 'B') {
                map[newX][newY] = 'D';
                q.push({newX, newY});
            }
        }
        q.pop();
    }
}

void newBfsRG() {
    while (!q.empty()) {
        int prevX = q.front().first;
        int prevY = q.front().second;
        if (map2[prevX][prevY] == 'R' || map2[prevX][prevY] == 'G') {
            res2++;
        }
        for (int i=0; i<4; i++) {
            int newX = prevX + xx[i];
            int newY = prevY + xy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if (map2[newX][newY] == 'R' || map2[newX][newY] == 'G') {
                map2[newX][newY] = 'S';
                q.push({newX, newY});
            }
        }
        q.pop();
    }
}

void newBfsB() {
    while (!q.empty()) {
        int prevX = q.front().first;
        int prevY = q.front().second;
        if (map2[prevX][prevY] == 'B') {
            res2++;
        }
        for (int i=0; i<4; i++) {
            int newX = prevX + xx[i];
            int newY = prevY + xy[i];
            if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
            if (map2[newX][newY] == 'B') {
                map2[newX][newY] = 'D';
                q.push({newX, newY});
            }
        }
        q.pop();
    }
}

int main() {

        cin >> n;

        for (int i = 0; i < n; i++) {
                cin >> s;
                for (int j = 0; j < n; j++) {
                    map[i][j] = s[j];
                    map2[i][j] = s[j];
                }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 'R') {
                    q.push({i, j});
                    bfsR();
                }
                if (map[i][j] == 'G') {
                    q.push({i, j});
                    bfsG();
                }
                if (map[i][j] == 'B') {
                    q.push({i, j});
                    bfsB();
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map2[i][j] == 'R' || map2[i][j] == 'G') {
                    q.push({i, j});
                    newBfsRG();
                }
                if (map2[i][j] == 'B') {
                    q.push({i, j});
                    newBfsB();
                }
            }
        }

//    for (int i=0; i<m; i++) {
//        for (int j=0; j<n; j++) {
//            cout << map[i][j] << ' ';
//        }
//        cout << '\n';
//    }

        cout << res << ' ' << res2;

}