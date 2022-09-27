#include <iostream>
#include <queue>
using namespace std;
int n,k;
vector<int> v;
int arr[2000001];
int main() {
    cin>>n;
    int cnt=0;
    for (int i=0;i<n;i++) {
        cin>>arr[i];
        cnt+=arr[i];
    }
    cin>>k;
    if (cnt <= k) {
        cout << -1;
        return 0;
    }
    int j = 0;
    int task = 0;

    while (task < k) {
        if (arr[j % n] == 0) {
            j++;
            continue;
        }
        arr[j % n]--;
        task++;
        j++;
    }
	
    while (arr[j % n] == 0) {
        j++;
    }
	
    cout << j%n+1;
}