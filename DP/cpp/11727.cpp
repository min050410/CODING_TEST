// 2xn 타일링 2

#include <iostream>
using namespace std;

long long int m[1000];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    m[1] = 1;
    m[2] = 3;
    for(int i=3; i<=n; i++)
    {
        m[i] = (m[i-1] + (2*m[i-2]))%10007;
    }
    cout << m[n];
}