#include<iostream>
#include<queue>
using namespace std;
int n, a;
priority_queue<int> pq;
int main() {
	cin >> n;
	for (int i=0;i<n;i++){
		cin >> a;
		pq.push(a);
	}
	int before = -1;
	int grade = 0;
	while (!pq.empty()) {
		int temp = pq.top();
		pq.pop();
		if (temp != before) {
			grade++;
		}
		if (grade==3) {
			cout << temp;
			break;
		}
		before = temp;
	}
}