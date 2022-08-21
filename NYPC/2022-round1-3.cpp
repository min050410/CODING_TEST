// 인류의 적 모기 퇴치 - 84

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100][100];
int max_int;
int cnt;

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
int mx2[4] = {1, -1, 1, -1};
int my2[4] = {1, - 1, -1, 1};


int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    // 십자가
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<=m; k++) {
                if (k == 0) {
                    cnt += arr[i][j];
                    continue;
                }
                for (int p=0; p<4; p++) {
                    int cy = i+(my[p]*k);
                    int cx = j+(mx[p]*k);
                    if (cy < n && cy >= 0 && cx < n && cy >= 0){
                        cnt += arr[cy][cx];
                    }
                }
            }
            max_int = max(max_int, cnt);
            cnt = 0;
        }
    }

    // 대각선
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<=m; k++) {
                if (k == 0) {
                    cnt += arr[i][j];
                    continue;
                }
                for (int p=0; p<4; p++) {
                    int cy = i+(my2[p]*k);
                    int cx = j+(mx2[p]*k);
                    if (cy < n && cy >= 0 && cx < n && cy >= 0){
                        cnt += arr[cy][cx];
                    }
                }
            }
            max_int = max(max_int, cnt);
            cnt = 0;
        }
    }

    cout << max_int;
}