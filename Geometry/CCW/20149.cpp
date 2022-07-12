// 선분 교차 3

// ccw 교차판별이 둘다 0일 때
// 예외 처리 1 ) 기울기가 같으면 
// 예외 처리 2 ) 기울기가 다르고 한 선분의 끝과 끝이 만날 때

// ccw 교차판별이 0보다 작거나 같은 때 
// 교차 공식 계산 -> 16자리까지 표시

// 나머지
// 교차 x 

#include <iostream>
#define ll long double
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
        // 기울기가 같으면
        if ((p2.y - p1.y) / (p2.x - p1.x) == (p4.y - p3.y) / (p4.x - p3.x)) {
            if (max(p1.x, p2.x) == min(p3.x, p4.x) && max(p1.y, p2.y) == min(p3.y, p4.y)) {
                cout << '\n' << min(p3.x, p4.x) << " " << min(p3.y, p4.y);
            }
            else if (min(p1.x, p2.x) == max(p3.x, p4.x) && min(p1.y, p2.y) == max(p3.y, p4.y)) {
                cout << '\n' << max(p3.x, p4.x) << " " << max(p3.y, p4.y);
            }
            else return 0;
        }
        else {
            // p1과 pn이 같은 점
            if (p1.x == p3.x && p1.y == p3.y) {
                cout << '\n' << p1.x << " " << p1.y;
            }
            else if (p1.x == p4.x && p1.y == p4.y) {
                cout << '\n' << p1.x << " " << p1.y;
            }
            // p2와 pn이 같은 점
            else {
                cout << '\n' << p2.x << " " << p2.y;
            }
        }
		return 0;
	}
    if (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0) {
        cout << 1 << '\n';
        ll pl = (p1.x * p2.y - p1.y * p2.x) * (p3.x - p4.x) - (p1.x - p2.x) * (p3.x * p4.y - p3.y * p4.x);
        ll pr = (p1.x * p2.y - p1.y * p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x * p4.y - p3.y * p4.x);
        ll p = (p1.x - p2.x)*(p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);
        cout << fixed;
        cout.precision(16);
        cout << pl/p << " " << pr/p;
    }
    else {
        cout << 0;
    }
}