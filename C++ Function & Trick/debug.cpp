#include <iostream>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
int main() {
    int a=2, b=4;
    debug(a);
    // 조건문이 거짓이면 에러 발생시킴
    assert(a==b);
}