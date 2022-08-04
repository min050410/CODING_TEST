// 구간 합 구하기 4

#include<iostream>
using namespace std;

int arr[100005];

int main(){
    int n,m;
    int a,b;

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    for(int i=0;i<m;i++){
        cin >> a >> b;

        cout << arr[b]-arr[a-1];
    }

    return 0;
}