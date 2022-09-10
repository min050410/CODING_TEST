// 신입 사원 

#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
int cnt[21];
pair<int,int> score[100000];
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> score[j].first >> score[j].second;
		}
		sort(score, score + n);
		int max_score = score[0].second;
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (score[i].second <= max_score) {
				c++;
				max_score = score[i].second;
			}
		}
		cnt[i] = c;
	}
	for (int i = 0; i < t; i++) {
		cout << cnt[i]<< '\n';
	}
	return 0;
} 