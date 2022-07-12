// 집합
// 시간초과 해결 : sync_with_stdio로 버퍼 쓰지 않기
// 메모리 초과 해결 : vector로 출력하지않고 바로 출력 

#include <iostream>
using namespace std;

int n;
string s;
int a;

unsigned int set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int t=0; t<n; t++) {
        cin >> s;
        if (s == "all") {
            set = 0b11111111111111111111;
        } else if (s == "empty") {
            set = 0;
        } else {
            cin >> a;
            if (s == "add") {
                set = set | (1 << a) / 2;
            } else if (s == "remove") {
                set = set & ~((1 << a) / 2);
            } else if (s == "toggle") {
                set = set ^ (1 << a) / 2;
            } else if (s == "check") {
                if ((set & (1 << a) / 2) == (1 << a) / 2) {
                    cout << 1 << '\n';
                } else {
                    cout << 0 << '\n';
                }
            }
        }
    }
    return 0;
}