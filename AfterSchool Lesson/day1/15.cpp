#include <iostream>
#define ll long long
#define inf 0x7fffffff

using namespace std;

int n;
int arr[200001];
int cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    // 에라토스테네스의 체
    for (int i=1; i<200001; i++) {
        arr[i] = 1;
    }

    for (int i=2; i<200001; i++) {
        for (int j=i*2; j<200001; j += i) {
            arr[j] = 0;
        }
    }

    for (int i=2; i<=n; i++) {
        cnt+=arr[i];
    }

    cout << cnt;
}
