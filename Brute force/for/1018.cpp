// 체스판 다시 칠하기

#include <iostream>
#define inf 0x7fffffff

using namespace std;

int n, m;
char arr[51][51];
int cntW;
int cntB;

int min_int = inf;

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<n-7; i++) {
        for (int j=0; j<m-7; j++) {
            for (int k=0; k<8; k++) {
                for (int t=0; t<8; t++) {
                    if ((k+t) % 2 == 0) {
                        if (arr[i+k][j+t]=='B') {
                            cntW++;
                        }
                        else {
                            cntB++;
                        }
                    }
                    else {
                        if (arr[i+k][j+t]=='B') {
                            cntB++;
                        }
                        else {
                            cntW++;
                        }
                    }
                }
            }
            min_int = min(min_int, cntW);
            min_int = min(min_int, cntB);
            cntB = 0;
            cntW = 0;
        }
    }
    cout << min_int;
}