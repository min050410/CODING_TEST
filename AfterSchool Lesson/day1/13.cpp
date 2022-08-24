#include <iostream>
#include <algorithm>
#include <queue>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n;
int cnt[10000];
int zari;
int max_int;
int many;
priority_queue<int> pq;

int main() {
    cin >> n;
    int temp = n;
    while (temp) {
        cnt[temp%10]++;
        zari++;
        temp = temp / 10;
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
