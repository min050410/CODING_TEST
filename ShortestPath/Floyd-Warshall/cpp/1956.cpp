// 운동

// 핵심 - floyd warshall의 대각선 원소들을 0으로 방치하지 않고 값을 구하면
// 사이클의 여부를 구할 수 있다 ( 값이 유한이면 사이클, 무한이면 사이클 아님 )
// 전체 노드의 사이클 여부를 확인할 때 floyd warshall 알고리즘으로 사이클을 구하면 유용하다.

#include <iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int inf = 10000000;
int n, m;
int a, b, cost, node, cnt;
int v[600][600];
int result = 100000000;

int main(){
	cin >> n >> m;

	// inf로 초기화
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			v[i][j] = inf;
			// 자기 자신은 0으로
			if (i==j){
				v[i][j] = 0;
			}
		}
	}
	
	// 입력
	for (int i=0; i<m; i++){
		cin >> a >> b >> cost;
		v[a][b] = cost;

	}

	// 점화식
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				if (v[i][k] && v[k][j]){
					if (v[i][j]!=0){
						v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
						
					}
					else{
						v[i][j] = v[i][k] + v[k][j];
					}
				}			
			}
		}
	}

	// 출력 - test
	// for (int i=1; i<=n; i++){
	// 		for (int j=1; j<=n; j++){
	// 			if (v[i][j]==inf){
	// 				cout << 0 << " ";
	// 			}
	// 			else{
	// 				cout << v[i][j] << " ";
	// 			}
	// 	}
	// 	cout << '\n';
	// }

	// 사이클 판별 
	for (int i=1; i<=n; i++){
		result = min(v[i][i], result);
	}

	if (result > inf){
		cout << -1;
	}
	else
		cout << result;
}
	




