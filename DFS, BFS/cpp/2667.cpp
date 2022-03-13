// 단지 번호 붙이기

#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int n, m, k;
int x, y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// 방문 - visited 
int vi[26][26];
// map
vector<int> v[26];

// result
int cnt;
vector<int> result;

void dfs(int l, int r){
  // 방문 설정
  vi[l][r] = 1;
  // 4방향으로 확인
  for(int i=0; i < 4; i++){
    int ny = dy[i] + l;
    int nx = dx[i] + r;
    // 범위 
    if(nx < n && nx >= 0 && ny < n && ny >= 0){
      // 방문하지 않은 노드 && 값이 1인 노드
      if(!vi[ny][nx] && v[ny][nx] == 1)
        dfs(ny, nx);
    }
  }
}

int main()
{
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      v[i].push_back(0);
    }
  }
  cin >> k;
	for(int i=0; i<k; i++){
    cin >> x >> y; 
    // xy 위치 바뀔 수도
    v[x][y] = 1;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(v[i][j]==1 && !vi[i][j]){
        dfs(i, j);
        cnt ++;
      }
    }
  }
  

  // 출력
	cout << cnt << '\n';
	
  return 0;
}
