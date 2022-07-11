// 상근이의 여행
// 최소 신장 트리의 간선은 n-1이라는 것을 이용하여 쉽게 풀었다.
// 실수한 점 : union find를 이용해 접근하려고 했다.

#include <iostream>
#include <vector>
using namespace std;

int t;
int n, m;
int a, b;


int main () {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        for (int j=0; j<m; j++) {
            cin >> a >> b;
        }
        cout << n-1 << '\n';
    }
}

