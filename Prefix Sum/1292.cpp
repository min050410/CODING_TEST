// 쉽게 푸는 문제

#include <iostream>
#define ll long long
using namespace std;

int arr[1000000];
ll ans[1000000];
ll n, m;
ll cnt;
int k;

int main(){

    cin >> n >> m;

    for (int i=1; i<=m; i++){
        for (int j=1; j<=i; j++) {
            k++;
            arr[k] = i;
            arr[k] += arr[k-1];
        }
    }

    cout << arr[m] - arr[n-1];

    return 0;
}