#include <iostream>
#include <stack>
using namespace std;
int n;
stack<int> s;
void res(int x) {
	if (x == 0) return;
	s.push(x%2);
	res(x/2);
}

int main () {
	cin>>n;
	res(n);
	while (!s.empty()) {
		cout<<s.top();
		s.pop();
	}
}