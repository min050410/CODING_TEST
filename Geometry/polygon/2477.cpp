// 참외밭

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int k;
int a;
int bx;
int by;
int s = 1;
int b[1000];
int idx;

pair<int, int> p[10000];

int main() {
    cin >> k;
    for (int i=1; i<=6; i++) {
        cin >> a >> b[i];
        if (i%2==0) {
            bx += b[i];
        }
        else {
            by += b[i];
        }
        for (int j=1; j<=6; j++) {
            if (p[j].second == a) {
                p[j] = {0, 0};
                continue;
            }
        }
        p[i] = {i, a};
    }
    for (int i=1; i<=6; i++) {
        // pj 다 출력해보기
        if (p[i].first != 0 && p[i].second != 0) {
            idx = i;
        }
    }
//    cout << b[(idx+2)%6] << " " << b[(idx+3)%6] << '\n';
    int s = b[(idx+2)%6] * b[(idx+3)%6];
    int bs = (bx/2) * (by/2);
    cout << bs << " " << s;
    s = bs - s;
    cout << k * s;
}