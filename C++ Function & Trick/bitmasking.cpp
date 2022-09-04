#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int a=4, b=2, c=8;
    // ~a = -a-1
    cout<<~a;
    // 짝수 판별
    if (a&1) cout<<"odd";
    else cout<<"even";
    // c의 이진법상 k+1번째 자릿수
    int k=3; cout<<(c>>k&1);
    // a, b의 평균
    cout<<(a+b>>1);
    // 비트 1의 개수
    cout<<__builtin_popcount(2);
}