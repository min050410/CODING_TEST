// 끝말잇기

#include <iostream>
using namespace std;
int n;
string a;
pair<char, char> b[1000];

int main() {
    cin >> n;
    bool flag = true;
    for (int i=0; i<n; i++) {
        cin >> a;
        b[i].first = a[0];
        b[i].second = a[a.length()-1];
    }

    for (int i=0; i<n-1; i++) {
        if (b[i].first != b[i+1].first || b[i].first != b[i].second || b[i].first != b[i+1].second) {
            flag = false;
        }
    }

    if (flag) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}