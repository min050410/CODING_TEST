// 단지 번호 붙이기

#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

// 방문
int vi[26][26];
// map
vector<int> v[26];

int cnt;
vector<int> result;

void dfs(int l, int r){
  vi[l][r] = 1;
  cnt++;
  for(int i=0; i < 4; i++){
    int ny = dy[i] + l;
    int nx = dx[i] + r;
    if(nx < n && nx >= 0 && ny < n && ny >= 0){
      if(!vi[ny][nx] && v[ny][nx] == 1)
        dfs(ny, nx);
    }
  }
}

int main()
{
  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%1d", &m);
      v[i].push_back(m);
      if(m==1 && !vi[i][j]){
        cnt = 0;
        dfs(i, j);
        result.push_back(cnt);
      }
    }
  }
  
  sort(result.begin(), result.end());

	cout << result.size() << '\n';
	
  for(auto const &r:result)
    cout << r << '\n';
  return 0;
}
