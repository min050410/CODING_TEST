// 터렛
#include <iostream>
#include <cmath>

int T;
int x, y, r;
int xx, yy, rr;
int dis, d, u;

using namespace std;

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> T;

    for (int i=0; i<T; i++){
        cin >> x >> y >> r >> xx >> yy >> rr;
        dis = pow(x - xx, 2) + pow(y - yy, 2);
        u = pow((r + rr),2);
        d = pow((r - rr),2);

        // 두 점이 같은 위치일 때 ( 두점사이 거리가 0 일때)
        if(dis == 0){
            if(d == 0) cout << -1 << '\n';
            else cout << 0 << '\n';
        }
        // 두 점 사이의 거리와 r1, r2 합의 제곱이 같거나 r1, r2 차의 제곱이 같으면 1개
        else if(u == dis || d == dis){
            cout << 1 << '\n';
        }
        // 그 중간
        else if(d < dis && dis < u){
            cout << 2 << '\n';
        }
        else cout << 0 << '\n';
    }
    return 0;
}