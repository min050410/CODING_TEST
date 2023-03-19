// 팩토리얼 0의 개수
// 0의 개수만 구하면 되는 문제였기에
// 1부터 n까지 모든 수의 약수의 2, 5의 개수를 구하고
// 2, 5가 곱해져 10이 만들어지므로 10이 만들어자는 2, 5 쌍의 개수를 출력했다.

#include <iostream>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;

ll n;
ll five;
ll two;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int t = i;
        while (!(t % 2) || !(t % 5)) {
            if (t % 5 == 0) {
                t/=5;
                five++;
            }
            if (t % 2 == 0) {
                t/=2;
                two++;
            }
        }
    }
    cout << min(five, two);
}