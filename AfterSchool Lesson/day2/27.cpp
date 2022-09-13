#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
	int n, i, j, tmp;
	scanf("%d", &n);
	vector<int> ch(n+1);
	for(i=2; i<=n; i++){
		tmp=i;
		j=2;
		// 소수 구하기
		while(1){
			// 나누어 떨어지면
			if(tmp%j==0){
				// ch[j] 1증가
				ch[j]++;
				// tmp 나누기
				tmp=tmp/j;
			}
			// 아니면 증가 tmp가 1일때까지
			else j++;
			if(tmp==1) break;
		}
	}
	printf("%d! = ", n);
	for(j=2; j<=n; j++){
		if(ch[j]!=0) printf("%d ", ch[j]);
	}
	return 0;
}