// PIZZA ALVOLOC
// 실수한것 : 곱셈 값이 너무 커져서 int 의 범위를 넘어감
// return 값을 1, 0, -1로 조정함

#include <iostream>
using namespace std;

int a[8];

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int op = (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
    if (op > 0) return 1;
    else if (op == 0) return 0;
    else return -1;
}

int main() {
    for (int i=0; i<8; i++) {
        cin >> a[i];
    }
    if (ccw(a[0], a[1], a[2], a[3], a[4], a[5]) * ccw(a[0], a[1], a[2], a[3], a[6], a[7]) < 0){
        cout << "1";
        return 0;
    }
    else {
        cout << "0";
        return 0;
    }
}