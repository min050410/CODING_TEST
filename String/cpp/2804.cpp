// 크로스워드 만들기

#include <iostream>
#include <cstring>
using namespace std;

//int n;
string a, b;
int x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    int flag = 0;
    for (int i=0; i<a.size(); i++) {
        for (int j=0; j<b.size(); j++) {
            if (a[i] == b[j]) {
                y = i;
                x = j;
                flag = 1;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    for (int i=0; i<b.size(); i++) {
        for (int j=0; j<a.size(); j++) {
            if (i == x) {
                cout << a[j];
            }
            else if (j == y) {
                cout << b[i];
            }
            else {
                cout << '.';
            }
        }
        cout << '\n';
    }

}