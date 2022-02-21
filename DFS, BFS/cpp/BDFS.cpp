#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int visited[1000];
int n, m, s, l, r;

void dfs(vector<int> graph[], int s, bool check[]){
  //recursion으로 구현 ㄱㄱ
  int temp = s;
  cout << s << " ";
  check[temp] = true;
  for(const auto &g:graph[temp]){
    if(check[g] == false){
      dfs(graph, g, check);
    }
  }
}

void bfs(vector<int> graph[], int s, bool check[]){
  // check 초기화
  fill(check, check+n+1, false);
  // 처음
  queue<int> q;
  q.push(s);
  // q가 빌때까지 반복
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    cout << temp << " ";
    check[temp] = true;
    for(const auto &g:graph[temp]){
      if(check[g]==false){
        q.push(g);
        check[g] = true;
      }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	  cout.tie(NULL);

    cin >> n >> m >> s;
    vector<int> graph[n+1];
    for(int i=0; i<m; i++){
      cin >> l >> r;
      graph[l].push_back(r);
      graph[r].push_back(l);
    }
    // sorting - 정점 번호가 작은곳 순서대로
    for(int i=1; i<=n; i++){
		  sort(graph[i].begin(), graph[i].end());
	  }
    bool check[n+1];
    //fill 공백으로 초기화 python에서는 fill = [False] * 9
    fill(check, check+n+1, false);

    dfs(graph, s, check);
    cout << "\n";
    bfs(graph, s, check);
    
    return 0;
}


