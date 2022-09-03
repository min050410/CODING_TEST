// 사진 작가

#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;
int cnt[1000001];
int arr[200001];
int len = 0;
int max_len = 0;
int n;

int main() {
    cin >> n;

    int e = 0;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int s=0; s<n; s++) {
        while (cnt[arr[e]] == 0 && e<n) {
            cnt[arr[e]]++;
            e++;
            len++;
            max_len = max(max_len, len);
        }
        if (e==n) break;
        cnt[arr[s]]--;
        len--;
    }
    cout << max_len;
}

