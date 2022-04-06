// 랜선 자르기
// parametric search

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int n, m, a;
int M = 0;
int arr[10001];

int isCorrect(int x){
    int cnt = 0;

    for (int i=0; i<n; i++){
        cnt += (arr[i] / x);
    }
    if (cnt >= m){
        return 1;
    }
    else {
        return 0;
    }
}

int BinarySearch(ll low, ll high, int x){

    if (low == high){
        return low;
    }

    ll mid = (low + high + 1) / 2 ;

    if (isCorrect(mid)){
        return BinarySearch(mid, high, x);
    }
    else {
        return BinarySearch(low, mid-1, x);
    }
}

int main(void) {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // n < m
    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> a;
        arr[i] = a;
        M = max(a, M);
    }

    cout << BinarySearch(0, M, M/2+1);
}