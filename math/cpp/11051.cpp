// 이항계수 2
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
        for (int j = 1; j <= b; j++)
        {
            arr[i][j] = arr[i - 1][j] % 10007 + arr[i - 1][j - 1] % 10007;
        }
    }
    return arr[a][b];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << C(a, b) % 10007 << '\n';
    return 0;
}