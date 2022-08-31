// 연산자 끼워넣기

#include <iostream>
#include <vector>
#define inf 0x7fffffff
using namespace std;
int n, a;
int arr[1000];
char ans[1000];
int checked[1000];
vector<char> oper;
int sz;
int m = inf;
int M = -1000000001;

void res(int x) {
    if (x == sz) {
        // 계산
        int result = arr[0];
        for (int i=0; i<sz; i++) {
            if (ans[i] == '*') {
                result *= arr[i+1];
            }
            if (ans[i] == '/') {
                result /= arr[i+1];
            }
            if (ans[i] == '+') {
                result += arr[i+1];
            }
            if (ans[i] == '-') {
                result -= arr[i+1];
            }
        }
        if (M < result) M = result;
        if (m > result) m = result;
    }
    for (int i=0; i<sz; i++) {
        if (!checked[i]) {
            checked[i] = 1;
            ans[x] = oper[i];
            res(x+1);
            checked[i] = 0;
        }
    }
}

void push_oper(int k, char x) {
    for (int i=0; i<k; i++) {
        oper.push_back(x);
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int i=0; i<4; i++) {
        cin >> a;
        if (i==0 && a) {
            push_oper(a, '+');
        }
        if (i==1 && a) {
            push_oper(a, '-');
        }
        if (i==2 && a) {
            push_oper(a, '*');
        }
        if (i==3 && a) {
            push_oper(a, '/');
        }
    }
    sz = oper.size();
    res(0);
    cout << M << '\n' << m;
}