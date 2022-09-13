#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[1000001];
int n;
int jumper[1000001];
int cnt[1000001];

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<n-1; i++) {
        jumper[i] = abs(arr[i] - arr[i+1]);
    }

    for (int i=0; i<n-1; i++) {
        cnt[jumper[i]]++;
    }
    int flag = 1;
    for (int i=1; i<n; i++) {
        if (!cnt[i]) {
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