// [연습문제] 레이스 기록 검증 - 100

#include <iostream>
#include <vector>
using namespace std;

int n, m;
pair<int, int> map[201];
int t, num, c;

int main() {
    int flag = 1;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> t >> num >> c;
        c++; // 0 -> 1, 1 -> 2
        // 처음
        if (map[num].second == 0 && c == 1) {
            map[num] = make_pair(t, c);   
        }
        // 끝 
        else if (map[num].second == 1 && c == 2) {
            if (t - map[num].first <= 59) {
                flag = 0; 
            }
            map[num] = make_pair(t, c);    
        }
		// 다시 시작
		else if (map[num].second == 2 && c == 1) {
			if (t - map[num].first == 0) {
				flag = 0;
			}
			map[num] = make_pair(t, c);
		}
        else {
            flag = 0;
        }
    }
    
    for (int i=1; i<=n; i++) {
		// 출발 해놓고 방치
        if (map[i].second == 1) {
            flag = 0;
        }
    }
    
    if (flag) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}