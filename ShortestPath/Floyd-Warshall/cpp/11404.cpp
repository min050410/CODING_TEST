// 플로이드
#include <iostream>
#include<vector>
#include <limits.h>
#include<string.h>
#include<algorithm>

using namespace std;

int inf = 99999;
int n, m;
int a, b, cost;
int v[101][101];

int main(){
	cin >> n >> m;

	// inf로 초기화
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			v[i][j] = inf;
			// 자기 자신은 0으로
			if(i==j){
				v[i][j] = 0;
			}
		}
	}
	
	// 입력
	for(int i=0; i<m; i++){
		cin >> a >> b >> cost; 	
		v[a][b] = cost;
		v[b][a] = cost;
	}
	// // 점화식 실행
	// for(int k=0; k<n; k++){
	// 	for(int i=0; i<n; i++){
	// 		for(int j=0; j<n; j++){
	// 			v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
	// 		}
	// 	}
	// }
	
	// 출력
	for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(v[a][b]==99999){
					cout << 0 << " ";
				}
				else{
					cout << v[i][j] << " ";
				}
		}
		cout << '\n';
	}
}



