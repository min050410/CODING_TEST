// 4단 for문을 이용해 푼 풀이

#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[150][150];
int w, h;
int M = 0;
int S(int y, int x) {
    int s = 0;
    for (int i=y; i<y+h; i++) {
        for (int j=x; j<x+w; j++) {
            s += arr[i][j];
        }
    }
    return s;
}

int main() {
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cin>>h>>w;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++){
            int temp = S(i, j);
            M = max(temp, M);
        }
    }
    cout << M;
}