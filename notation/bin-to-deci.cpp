#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

char arr[100000];
int n, s;
int num;
int n1, n2;


// 2진수 > 10진수
int ten(){
	for (int i=0; arr[i]!='\0'; i++){
		s = i;
	}
	for (int i=0; arr[i]!='\0'; i++){
		if(arr[i]=='1'){
			num += (pow(2,s));
			// cout << num1 << " ";
		}
		s--;
	}
	
	return num;
}

// 10진수 > 2진수
void two(int num){
	vector<int> res;
	while (num != 0){
		res.push_back(num % 2);
		num /= 2;
	}
	for (int i=0; i<10-res.size(); i++){
		cout << 0;
	}
	for (int i=res.size()-1; i>=0; i--){
		cout << res[i];
	}
	cout << '\n';
}

// 10진수 > 2진수(not)
void nottwo(int num){
	vector<int> res;
	while (num != 0){
		res.push_back((num % 2)==1?0:1);
		num /= 2;
	}
	for (int i=0; i<10-res.size(); i++){
		cout << 1;
	}
	for (int i=res.size()-1; i>=0; i--){
		cout << res[i];
	}
	cout << '\n';
}

int main() {

	cin >> arr;
	n1 = ten();
	memset(arr, 0 , sizeof(arr));
	num=0;
	cin >> arr;
	n2 = ten();
	
	two(n1&n2);
	two(n1|n2);
	two(n1^n2);

	nottwo(n1);
	nottwo(n2);
	
	return 0;
}