// backjun 미로 탐색

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
vector<int> map[100];

void bfs(){
  // queue 생성 & 초기화
  queue<pair<int, int>> q;
  q.push(make_pair(0,0));
  // q가 빌 때까지
  while(!q.empty()){
    pair<int, int> temp = q.front();
    q.pop();
    for(int i=0; i<4; i++){
      // 근처에 있는 노드들
      int mx = temp.first + dx[i];
      int my = temp.second + dy[i];
      if(mx >= 0 && my >= 0 && mx < n && my < m && map[mx][my]==1){
        q.push(make_pair(mx, my));
        // +1 하기 count 이용해서 미로 거리 구하기
        map[mx][my] = map[temp.first][temp.second] + 1; 
      }
    }
  }
  return;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
	// cout.tie(NULL);

    cin >> n >> m;
     
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%1d", &num);
            map[i].push_back(num);
        }

    bfs();

    cout << map[n-1][m-1];

}



