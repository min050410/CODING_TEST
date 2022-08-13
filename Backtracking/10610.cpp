// 30

#include <iostream>
#include <algorithm>
#define ll long long
#define INF 0xffffff7
using namespace std;

string n;
int a[1000000];
int num[1000000];
int comp;

bool is_used(int a, int x){
    for (int i=0; i<a; i++){
        if (num[i] == x){
            return true;
        }
    }
    return false;
}

void res(int x) {
    if (x == n.length()) {
        for (int i=0; i<n.length(); i++) {
            cout << num[i];
//            comp = (comp * 10) + num[i];
        }
        cout << '\n';
//        if (comp % 30 == 0) {
//            cout << comp;
//            return;
//        }
//        else {
//            comp = 0;
//        }
    }
    for (int i=0; i<n.length(); i++) {
        num[x] = a[i];
        if (!is_used(x, a[i])){
            res(x+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i=0; i<n.length(); i++) {
        a[i] = n[i] - '0';
    }
    sort(a, a+n.length(), greater<>());
//    for (int i=0; i<n.length(); i++) {
//        cout << a[i] << ' ';
//    }
//    cout << '\n' << '\n';
    res(0);
}