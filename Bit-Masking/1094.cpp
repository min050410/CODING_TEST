// 막대

#include <iostream>

using namespace std;

int len;

int bitCount(int x) {
    if (x==0) return 0;
    return x % 2 + bitCount(x / 2);
}


int main() {
    cin >> len;
    cout << bitCount(len);
}


