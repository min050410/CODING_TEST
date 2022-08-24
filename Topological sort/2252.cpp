#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int inDegree[100000];
vector<int> v[100000];
vector<int> result;
vector<int> enter_zero;
int n, m;
int a, b;
int temp;
queue<int> q;

void topologi(){
	for(int i=1; i<=n; i++){
		if(inDegree[i] == 0){
			enter_zero.push_back(i);
			// cout << i << " ";
		}
	}

	for(int j=0; j<enter_zero.size(); j++){
		q.push(enter_zero[j]);
		while(!q.empty()){
			temp = q.front();
			result.push_back(temp);
			q.pop();
			for(int i=0; i<v[temp].size(); i++){
				// 진입차수 제거
				inDegree[v[temp][i]]--;
				if(inDegree[v[temp][i]]==0){
					q.push(v[temp][i]);
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i=0; i<m; i++){
		cin >> a >> b;
		v[a].push_back(b);	
		inDegree[b]++;
	}
	// for(int l=0; l<=n; l++){
	// 	cout << inDegree[l] << " ";
	// }
	// cout << '\n';
	topologi();
	for (const auto &r: result){
		cout << r << " ";
	}
}