// 개미
// 틀린 이유 : flag 초기화를 안함

#include <iostream>

using namespace std;

int n, m;
int a, b;
int k;

int main() {
    cin >> n >> m;
    cin >> a >> b >> k;

//    cout << k << '\n';

    int kw = k % (n * 2);
    int kh = k % (m * 2);

//    cout << kw << " " << kh << '\n';

    bool flag = false;
    while (kw) {
        if (!flag) {
            a++;
        }
        else {
            a--;
        }
        if (a >= n) {
            flag = true;
        }
        if (a <= 0) {
            flag = false;
        }
        kw--;
    }

    // 초기화
    flag = false;
    while (kh) {
        if (!flag) {
            b++;
        }
        else {
            b--;
        }
        if (b >= m) {
            flag = true;
        }
        if (b <= 0) {
            flag = false;
        }
        kh--;
    }

    cout << a << " " << b;
}