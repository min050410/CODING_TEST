#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];
int n, m;
int max_int = -100000001;
int s;

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<n-m+1; i++) {
        for (int j=0; j<m; j++) {
            s += arr[i+j];
        }
				// cout << s << '\n';
        max_int = max(max_int, s);
        s = 0;
    }

    cout << max_int;
}