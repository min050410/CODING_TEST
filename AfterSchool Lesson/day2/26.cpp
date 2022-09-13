#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int arr[100001];
int pre[100001];
int cnt;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<n; i++) {
        cnt = i+1;
        for (int j=0; j<i; j++) {
						// 실력이 같다면 앞에선수를 앞지를 수 없습니다.
            if (arr[j] < arr[i]) {
                cnt--;
            }
        }
        pre[i] = cnt;
    }
    for (int i=0; i<n; i++) {
        cout << pre[i] << ' ';
    }
}