// 경로 찾기

#include <iostream>
#include<vector>
#include <limits.h>
#include<string.h>
#include<algorithm>

using namespace std;

int inf = 99999;
int n, m;
int v[101][101];

int main(){
	cin >> n;
	
	// 입력
	for (int a=0; a<n; a++){
		for (int b=0; b<n; b++){
			cin >> v[a][b];
			if (v[a][b]==0){
				v[a][b] = inf;
			}
		}
	}
	// 점화식 실행
	for (int k=0; k<n; k++){
		for (int a=0; a<n; a++){
			for (int b=0; b<n; b++){
				v[a][b] = min(v[a][b], v[a][k]+v[k][b]);
			}
		}
	}
	// 출력
	for (int a=0; a<n; a++){
			for (int b=0; b<n; b++){
				if (v[a][b]==inf){
					cout << 0 << " ";
				}
				else 
					cout << 1 << " ";
		}
		cout << '\n';
	}
}



