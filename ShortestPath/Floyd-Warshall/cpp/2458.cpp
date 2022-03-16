// 키 순서

#include <iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int inf = 10000000;
int n, m;
int a, b;
int v[600][600];
int cnt, res;

int main(){
	cin >> n >> m;

	// inf로 초기화
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			v[i][j] = inf;
			// 자기 자신은 0으로
			if(i==j){
				v[i][j] = 0;
			}
		}
	}
	
	// 입력
	for (int i=0; i<m; i++){
		cin >> a >> b;
		v[a][b] = 1;

	}

	// 점화식
	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
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

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if ((v[i][j]!=inf || v[j][i]!=inf) && (i!=j)){
				cnt++;	
			}
		}
		// cout << cnt << '\n';
		if (cnt==n-1){
			res++;
		}
		cnt = 0;
	}

	cout << res;
}
