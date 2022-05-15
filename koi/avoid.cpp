// 피하자

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, x;
int a[10000000];
int b[10000000];

int cnt1; 
int cnt2;
int temp;

int j;

int main() {

	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> x;
		a[i] = x;
		b[i] = x;
	}
	
	// 짝수가 모두 왼쪽으로 가는 경우
	for (int i=0; i<n; i++){
		if (a[i] % 2 == 0){
			j = i;
			while(j){
				if (j!=0){
					if (a[j-1] % 2 != 0){
						cnt1++;
						temp = a[j-1];
						a[j-1] = a[j];
						a[j] = temp;
					}
					else {
						break;
					}
				}
				j--;
			}
		}
	}

	// 홀수가 모두 왼쪽으로 가는 경우
	for (int i=0; i<n; i++){
		if (b[i] % 2 != 0){
			j = i;
			while(j){
				if (j!=0){
					if (b[j-1] % 2 == 0){
						cnt2++;
						temp = b[j-1];
						b[j-1] = b[j];
						b[j] = temp;
					}
					else {
						break;
					}
				}
				j--;
			}
		}
	}

	cout << min(cnt1, cnt2);
}
