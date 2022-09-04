#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;
int main() {
    int x=1;
    int a=2, b=4;
    // 절댓값
    cout<<abs(x);
    // 최대공약수
    cout<<gcd(a,b);
    // 최소공배수
    cout<<lcm(a,b);
    // 제일 큰 원소
    cout<<max({a,b,x});
}