// code up 미로찾기 풀던 중 저장

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 미로의 행, 열
int n, m;
// 미로
int map[10000][10000];
// 현재 위치
int sx, sy;
// 방향
int x;
// 도착 지점
int ex, ey;

int cnt;

// 우, 밑, 왼, 위
int mx[4] = {1, 0, -1, 0};
int my[4] = {0, -1, 0, 1};
bool visited[1000][1000];
queue<pair<int, int>> q;

void bfs(){
    visited[sx][sy] = true;
    q.push({sx, sy});
    while (!q.empty()){
        pair temp = q.front();
        visited[temp.first][temp.second] = true;
        q.pop();
        for (int i=0; i<4; i++){
            int mdx = temp.first + mx[i];
            int mdy = temp.second + my[i];
            if (!map[mdx][mdy] && !visited[mdx][mdy] && mdx >= 0 && mdx < n && mdy >=0 && mdy < m){
                if (mdx == ex && mdy == ey){
                    return;
                }
                q.push({mdx, mdy});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    for (int i=0; i<m; i++){
        for (int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    cin >> sx >> sy;
    cin >> x;
    cin >> ex >> ey;
    bfs();
    return 0;
}
