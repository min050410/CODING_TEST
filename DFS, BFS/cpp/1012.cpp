// 1012 유기농 배추


#include <iostream>
#include <algorithm>
#include<vector>
#include<string.h>

using namespace std;

int t, times;
int n, m, k;
int x, y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// 방문 - visited 
int vi[51][51];
// map
vector<int> v[51];

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
	cin >> t;
	for(times = 0; times<t; times++){
	  cin >> n >> m;
	  for(int i=0; i<n; i++){
	    for(int j=0; j<m; j++){
	      v[i].push_back(0);
	    }
	  }
	  cin >> k;
		for(int i=0; i<k; i++){
	    cin >> y >> x; 
	    // xy 위치 바뀔 수도
	    v[y][x] = 1;
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

		// 초기화
		cnt = 0;
		memset(vi, 0, sizeof(vi));
		memset(v, 0, sizeof(v));
	}
  return 0;
}
