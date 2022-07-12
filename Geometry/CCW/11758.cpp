// ccw

#include <iostream>
using namespace std;

int x1, y1, x2, y2, x3, y3;

int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int abx = x2 - x1;
    int aby = y2 - y1;
    int bcx = x3 - x2;
    int bcy = y3 - y2;
    if ((abx * bcy - aby * bcx) > 0) {
        cout << 1;
    }
    else if ((abx * bcy - aby * bcx) == 0){
        cout << 0;
    }
    else {
        cout << -1;
    }
}