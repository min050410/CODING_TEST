// 동전 0

#include <iostream>
using namespace std;
int arr[12];
int main(){
	int a,b,c=0;
	cin >> a >> b;
	for (int i = 1;i <= a; i++){
		cin >> arr[i];
	}
	int i = a;
	while (b){
		while (b - arr[i] >= 0){
			b -=arr[i];
			c++;
		}
		i--;
	}	
	cout << c;
}