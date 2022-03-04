// 바이러스

#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int n, m;
int a, b;
int cnt;

bool check[1000];
vector<int> v[1000];

void dfs(int x){
	// cout << x << endl;
	check[x] = true;
	for(auto const &node:v[x]){
		if(check[node] == false){
			cnt++;
			dfs(node);
		}
	}
}

int main(){
	// 노드의 수	
	cin >> n;
	// 간선의 수
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	cout << cnt;
}
