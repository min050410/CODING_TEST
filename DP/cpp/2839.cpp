// 설탕 배달 - 백준 2889 브1

#include <iostream>
using namespace std;
int memo[5001];
int main()
{
    int x;
    cin >> x;

    //memo 3과 5를 1로 설정
    memo[3] = memo[5] = 1;

    for (int i = 6; i <= x; i++)
    {
        if (memo[i - 3])
            memo[i] = memo[i - 3] + 1;
        if (memo[i - 5])
            memo[i] = memo[i] ? memo[i] = min(memo[i], memo[i - 5] + 1) : memo[i] = memo[i - 5] + 1;
    }
    if (memo[x] == 0)
        cout << -1;
    else
    {
        cout << memo[x];
        //   for(int i=1; i<=18; i++){
        //     cout << memo[i] << '\n';
        //   }
    }
}
