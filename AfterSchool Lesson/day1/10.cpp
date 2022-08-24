#include <iostream>
#include <queue>
#include <algorithm>

#define ll long long
#define inf 0x7fffffff

using namespace std;

priority_queue<int> pq;
int t;
string n[1000];
int num;
int n_int;
int max_num;
string memo;

int main() {
    cin >> t;

		// 자릿수 합 최대 판별 
    for (int T=0; T<t; T++) {
        cin >> n[T];
        for (int i = 0; i < n[T].size(); i++) {
            num += n[T][i] - '0';
        }
        if (num > max_num) {
            max_num = num;
            memo = n[T];
        }
        num = 0;
    }

		// 자릿수 합 여러개일 때
    for (int T=0; T<t; T++) {
        for (int i = 0; i < n[T].size(); i++) {
            num += n[T][i] - '0';
            n_int = (n_int*10)+(n[T][i]-'0');
        }
        if (num == max_num) {
            pq.push(n_int);
        }
        num = 0;
        n_int = 0;
    }
    cout << pq.top();
}
