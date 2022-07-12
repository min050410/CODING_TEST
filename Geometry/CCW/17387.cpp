// 선분 교차 2
// double 자료형으로 설정해야 오버플로우가 발생하지 않는다.

#include <iostream>
#define ll double
using namespace std;

ll x1, y1, x2, y2, x3, y3, x4, y4;


class point {
    public:
        ll x;
        ll y;
        point(ll x, ll y):x(x), y(y) {};
};


int ccw(point p1, point p2, point p3) {
    ll abx = p2.x - p1.x;
    ll aby = p2.y - p1.y; 
    ll bcx = p3.x - p2.x;
    ll bcy = p3.y - p2.y;
    if ((abx * bcy - aby * bcx) > 0) {
        return 1;
    }
    else if ((abx * bcy - aby * bcx) == 0){
        return 0;
    }
    else {
        return -1;
    }
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    point p1 = point(x1, y1);
    point p2 = point(x2, y2);
    point p3 = point(x3, y3);
    point p4 = point(x4, y4);
	if (ccw(p1, p2, p3) * ccw(p1, p2, p4) == 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) == 0) {
		if(max(p1.x, p2.x) < min(p3.x, p4.x)) {cout << 0; return 0;}
		if(min(p1.x, p2.x) > max(p3.x, p4.x)) {cout << 0;return 0;}
		if(max(p1.y, p2.y) < min(p3.y, p4.y)) {cout << 0;return 0;}	
		if (min(p1.y, p2.y) > max(p3.y, p4.y)) {cout << 0; return 0;}
		else cout << 1;
		return 0;
	}
    if (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}	