// 생일

#include <iostream> 
#include <cmath>
#include <queue>
#define inf 0x7fffffff
using namespace std;

priority_queue<pair<int, string>> pq;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> min_pq;

int n;
string a;
int b, c, d;

int main() {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a >> b >> c >> d;
		int year = (d*10000+c*100+b);
		pq.push({year, a});
		min_pq.push({year, a});
	}
	cout << pq.top().second << endl;
	cout << min_pq.top().second;
}