#include <iostream>
using namespace std;
int n;
void res(int x) {
	if (x > n) return;
	cout<<x<<" ";
	res(++x);
}

int main () {
	cin>>n;
	res(1);
}