#include <iostream>
using namespace std;
int n, a;
int arr[1000];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a;
        int cnt = 0;
        for (int j=0; j<=a+cnt; j++) {
           if (arr[j] != 0 && arr[j] < i) cnt++;
        }
        arr[cnt+a] = i;
    }
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<' ';
    }
}