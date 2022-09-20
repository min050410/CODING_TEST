#include <iostream>
#include <queue>
using namespace std;
int n,k;
int arr[100][100];
int mx[4] = {0, 1, 0, -1};
int my[4] = {1, 0, -1, 0};

bool isPeaks(int y, int x) {
    bool flag = true;
    for (int i=0;i<4;i++){
        int ty = y+my[i];
        int tx = x+mx[i];
        if (ty >= 0 && tx >= 0 && ty < n && tx < n) {
            if (arr[ty][tx] > arr[y][x]) {
                flag = false;
                break;
            }
        }
    }
//    if (flag) {
//        cout << arr[y][x] << ' ';
//    }
    return flag;
}

int main() {
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int cnt = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (isPeaks(i, j)) {
                cnt++;
            }
        }
    }
    cout<<cnt;
}