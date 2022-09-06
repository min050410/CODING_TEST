// 다리 놓기
// 시간복잡도 : O(n)
// 조합에도 dp가 쓰임 ex) 4C2 = 3C2 + 3C1
#include <iostream>
using namespace std;
int arr[1001][1001];
int C(int a, int b)
{
    for (int i = 0; i <= a; i++)
        arr[i][0] = 1;
    for (int i = 0; i <= b; i++)
        arr[i][i] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
        }
    }
    return arr[a][b];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << C(b, a) << '\n';
    }
    return 0;
}