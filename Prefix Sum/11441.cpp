// 합 구하기

#include<iostream>
using namespace std;

int arr[100005];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        cout << arr[b]-arr[a-1] << '\n';
    }
    return 0;
}