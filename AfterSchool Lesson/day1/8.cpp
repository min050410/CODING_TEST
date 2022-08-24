#include <iostream>
#include <stack>
#include <algorithm>
#define ll long long
#define inf 0x7fffffff

using namespace std;

string a;
stack<int> s;

int main() {
    int flag = 1;
    cin >> a;
    for (int i=0; i<a.size(); i++) {
        if (a[i] == '(') {
            s.push(1);
        }
        else {
            if (s.empty()) {
                flag = 0;
                break;
            }
            else {
                s.pop();
            }
        }
    }

    if (flag) {
        if (!s.empty()) {
            cout << "NO";
        }
        else {
            cout << "YES";
        }
    }
    else {
        cout << "NO";
    }
}
