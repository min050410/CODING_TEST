#include <iostream>
#include <queue>
using namespace std;
int n,k;
vector<int> v;
int arr[2000001];
int main() {
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cin>>k;
    int j = 0;
    for (int i=0;i<k+1;i++) {
        int task = 0;
        while (arr[j % n] == 0) {
            j++;
            task++;
            if (task > n + 1) break;
        }
        if (task > n + 1) {
            cout << -1;
            return 0;
        }
        arr[j % n]--;
    }
    cout << j%n+1;
}