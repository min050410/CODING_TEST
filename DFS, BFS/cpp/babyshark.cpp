// 아기 상어

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>


using namespace std;

int board[22][22];
int check[22][22];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int second = 0, babysize = 2, N, x, y;
int eatfish = 0;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}
	
	while (1) {
		for (int i = 0; i <= N; i++)
			for (int j = 0; j <= N; j++)
				check[i][j] = -1;
		check[x][y] = 0;
		board[x][y] = 0;
		queue<pair<int, int>> q;
		vector<pair<int, int>> fish;
		if (eatfish >= babysize) {
			eatfish -= babysize;
			babysize++;
		}
		q.push({ x,y });
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				
				if (check[nx][ny] != -1) continue;
				if (board[nx][ny] > babysize) continue;
				
				else if (board[nx][ny] == babysize || board[nx][ny] == 0) {
					check[nx][ny] = check[cur.first][cur.second] + 1;
					q.push({ nx,ny });
				}
				else if(board[nx][ny] < babysize && board[nx][ny] >= 1){					
					check[nx][ny] = check[cur.first][cur.second] + 1;
					fish.push_back({ nx,ny });
					q.push({ nx,ny });
				}
			}
		}			
		if (fish.size() == 0) {
			cout << second << "\n";
			return 0;
		}
		else if (fish.size() == 1) {
			x = fish[0].first;
			y = fish[0].second;
			board[x][y] = 0;
			eatfish++;
			second += check[x][y];
		}
		else {
			int mindist = 1e5;
			for (auto& x : fish) {
				mindist = min(mindist, check[x.first][x.second]);
			}
			int mincnt = 0;
			vector<pair<int, int>> minfish;
			for (auto& x : fish) {
				if (mindist == check[x.first][x.second]) {
					minfish.push_back({ x.first,x.second });
				}
			}
			if (minfish.size() == 1) {
				x = minfish[0].first;
				y = minfish[0].second;
				board[x][y] = 0;
				second += check[x][y];
				eatfish++;
			}
			else {
				sort(minfish.begin(), minfish.end());
				x = minfish[0].first;
				y = minfish[0].second;
				second += check[x][y];
				board[x][y] = 0;
				eatfish++;
			}
		}
	}
}
[출처] [백준] 16236번 아기 상어 c++|작성자 류리