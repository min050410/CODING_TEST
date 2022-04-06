#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int a;
vector<int> v;

// 기본 이진탐색
int BSearch(int low, int high, int x){

    if (low > high){
        return 0;
    }

    int mid = (high + low)/2;

    if (x == v[mid]){
        return 1;
    }
    else if (x > v[mid]){
        return BSearch(mid+1, high, x);
    }
    else {
        return BSearch(low, mid-1, x);
    }
}

// upper bound idx 반환
int BSupper(int low, int high, int x){

    if (low == high){
        return low;
    }

    int mid = (high + low)/2;

    if (x >= v[mid]){
        return BSupper(mid + 1, high, x);
    }
    else {
        return BSupper(low, mid, x);
    }
}

// lower bound idx 반환
int BSlower(int low, int high, int x){

    int mid = (high + low)/2;

    if (low == high){
        return low;
    }

    if (x <= v[mid]){
        return BSlower(low, mid, x);
    }
    else {
        return BSlower(mid + 1, high, x);
    }
}

int main(void) {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for (int i=0; i<m; i++){
        cin >> a;
        int lowerbound = 0;
        int upperbound = 0;
        if (BSearch(0, v.size(), a)){
            lowerbound = BSlower(0,v.size(),a);
            upperbound = BSupper(0,v.size(),a);
        }
        cout << upperbound-lowerbound << " ";
    }
}