#include<iostream>
#include<algorithm>
using namespace std;
int a[1001], n;
int Count(int s){
	int i, cnt=1, sum=0;
	for(i=1; i<=n; i++){
		if(sum+a[i]>s){
			cnt++;
			sum=a[i];
		}
		else sum=sum+a[i];
	}
	return cnt;
}
int main(){
	int m, i, lt=1, rt=0, mid, res, maxx=-2147000000;
	cin>>n>>m;
	for(i=1; i<=n; i++){
		cin>>a[i];
		rt=rt+a[i];
		if(a[i]>maxx) maxx=a[i];
	}
	// maxx에는 최댓값 저장, rt에는 합 저장
	
	// 합에 대해 이진 탐색
	while(lt<=rt){
		mid=(lt+rt)/2;
		// Count(mid)는 mid를 넘지 않는 DVD 묶음 개수
		if(mid>=maxx && Count(mid)<=m){	
			res=mid;
			rt=mid-1;
		}
		else lt=mid+1;
	}
	cout<<res<<'\n';
	return 0;
}
