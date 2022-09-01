// 하키

#include <iostream>
#include <cmath>
using namespace std;
int W, H, X, Y, P;
int x, y;
int cnt;

int main() {
    cin >> W >> H >> X >> Y >> P;
    for (int i=0; i<P; i++) {
        cin >> x >> y;
        // 왼쪽 원
        int r = H/2;
        int a = X;
        int b = Y+r;
        if (pow(x-a,2) + pow(y-b, 2) <= pow(r, 2)) {
            cnt++;
            continue;
        }
        // 오른쪽 원
        a = X+W;
        b = Y+r;
        if (pow(x-a,2) + pow(y-b, 2) <= pow(r, 2)) {
            cnt++;
            continue;
        }
        // 직사각형
        if (X <= x && x <= X+W && Y <= y && y <= Y+H) {
            cnt++;
        }
    }
    cout << cnt;
}