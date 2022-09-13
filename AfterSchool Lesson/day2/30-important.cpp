#include<stdio.h>
int main(){
	int n, left=1, right, cur, k=1, res=0;
	// n이 131일 때
	scanf("%d", &n);
	while(left != 0){
		// 처음 left는 3
		left=n/(k*10);
		// 처음 right는 0
		right=n%k;
		// 처음 cur는 1
		cur=(n/k)%10;
		// 3 13 23 처리
		if(3<cur){
			// 왼쪽 수 +1 만큼 k 곱하기 +1의 이유는 3이 포함되기 때문
			// 만약 n=143에서 cur가 4라면 k가 10이므로
			// 2*k = 20 (31 32 33 .......39) 10개, (131, 132, 133, ......139) 10개
			res=res+((left+1)*k);
		}
		else if(3==cur){
			// left*k 는 30번대 처리
			// right + 1은 130 131 132 처리
			res=res+((left*k)+(right+1));
		}
		// 왼쪽 수 만큼 k 곱하기
		else res=res+(left*k);	
		k=k*10;
	}
	printf("%d\n", res);
	return 0;
}