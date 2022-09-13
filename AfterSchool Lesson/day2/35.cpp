#include <iostream>
using namespace std;
int n;
int arr[1000];
int sorted[1000];
int main() {
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>arr[i];
	}
	int j=0;
	for (int i=0;i<n;i++) {
		if (arr[i]<0){
			sorted[j++]=arr[i];	
		}
	}
	for (int i=0;i<n;i++) {
		if (arr[i]>0){
			sorted[j++]=arr[i];	
		}
	}
	for (int i=0;i<n;i++) {
		cout<<sorted[i]<<' ';
	}
}