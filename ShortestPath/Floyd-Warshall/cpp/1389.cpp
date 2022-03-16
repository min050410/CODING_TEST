// 케빈 베이컨의 6단계 법칙

#include <iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int inf = 10000000;
int n, m;
int a, b;
int temp, idx, result;
int min_value = 10000000;
int v[101][101];

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
		// 친구 관계
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

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
				temp += v[i][j];
		}
		// cout << temp;
		if (temp < min_value){
			min_value = temp;
			idx = i;
		}
		temp = 0;
	}
	cout << idx;
}
	




