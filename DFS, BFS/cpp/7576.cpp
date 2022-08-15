// 토마토

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int res;
int xx[4] = {0, 1, 0, -1};
int xy[4] = {1, 0, -1, 0};
int map[1001][1001];
queue<pair<int, int>> q;

int main() {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({i, j});
			}
		}
	}

	while (!q.empty()) {
		int prevX = q.front().first;
		int prevY = q.front().second;
		for (int i=0; i<4; i++) {
			int newX = prevX + xx[i];
			int newY = prevY + xy[i];
			if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
			if (map[newX][newY] == 0) {
				map[newX][newY] = map[prevX][prevY] + 1;
				res = map[newX][newY];
				q.push({newX, newY});
			}
		}
		q.pop();
	}

	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (map[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	if (res == 0) {
		cout << 0;
	}
	else {
		cout << res-1;	
	}
}