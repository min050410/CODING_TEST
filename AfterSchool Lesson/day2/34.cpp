#include <iostream>
using namespace std;
int n;
int arr[10000];
int main() {
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	for (int i=0;i<n;i++){
		for (int j=1;j<n-i;j++){
			if (arr[j-1]>arr[j]){
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i=0;i<n;i++){
		cout<<arr[i]<<' ';
	}
}