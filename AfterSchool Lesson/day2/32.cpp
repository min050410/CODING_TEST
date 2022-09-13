#include <iostream>
#include <algorithm>
#include <cmath>
#define inf 0x7fffffff
using namespace std;

int n;
int arr[1000001];
int min_int=inf;
int idx;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<n; i++) {
        min_int = arr[i];
        idx = i;
        for (int j=i+1; j<n; j++) {
            if (min_int > arr[j]) {
                idx=j;
                min_int = arr[j];
            }
        }
        swap(arr[i], arr[idx]);
    }

    for (int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
}