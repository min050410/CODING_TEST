// TLE : 자연수의 길이는 최대 100이란걸 간과했다. string으로 입력받아 해결했다.

#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
#define inf 0x7fffffff

using namespace std;

string n;
int cnt[10000];
int zari;
int max_int;
int many;
priority_queue<int> pq;

int main() {
    cin >> n;
    for (int i=0; i<n.size(); i++) {
				cnt[n[i] - '0']++;
				zari++;
		}
    for (int i=0; i<=9; i++) {
        if (max_int < cnt[i]) {
            max_int = cnt[i];
        }
    }

    for (int i=1; i<=9; i++) {
        if (cnt[i] == max_int) {
            pq.push(i);
        }
    }

    cout << pq.top();
}
